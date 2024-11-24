/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:56:30 by cschnath          #+#    #+#             */
/*   Updated: 2024/11/25 00:10:53 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_random_julia(double *real, double *imag, t_fractal *fractal)
{	
	t_fractal c;
	
	*real = (((double)rand() / RAND_MAX) * 3.0 - 1.5);
	*imag = (((double)rand() / RAND_MAX) * 3.0 - 1.5);
	c.real = *real;
	c.imag = *imag;
	ft_draw_julia(fractal, c);
}

// C should be constant
int	ft_julia(t_fractal *fractal, t_fractal c)
{
	int			i;
	t_fractal	z;
	t_fractal	temp_z;

	i = 0;
	fractal->name = "j";
	// Initialize z and iterate over every pixel
	z.real = ft_map_to_real(fractal->real, fractal->offset_x, fractal->offset_x
			+ fractal->width / fractal->zoom, fractal);
	z.imag = ft_map_to_imag(fractal->imag, fractal->offset_y, fractal->offset_y
			+ fractal->height / fractal->zoom, fractal);
	// Iterate while |z|^2 <= 4 and the maximum iteration limit isn't reached
	while (((z.real * z.real) + (z.imag * z.imag)) <= 4 && i < MAX)
	{
		temp_z = z;
		// Calculate z = z^2 + c
		z.real = (temp_z.real * temp_z.real) - (temp_z.imag * temp_z.imag)
			+ c.real;
		z.imag = 2 * temp_z.real * temp_z.imag + c.imag;
		i++;
	}
	// Generate the pixel color based on the base color and iteration count
	unsigned int color_modifier = (i * 0x010101) & 0xFFFFFF; // Gradual fade
	unsigned int pixel_color = fractal->color + color_modifier;

	// Apply the pixel color
	if (i == MAX)
		ft_color_pixel(fractal, fractal->real, fractal->imag, 0x000000);
	else
		ft_color_pixel(fractal, fractal->real, fractal->imag, pixel_color);
	return (i);
}

void	ft_draw_julia(void *fractal_void, t_fractal c)
{
	t_fractal	*fractal;
	int			x;
	int			y;
	
	fractal = (t_fractal *)fractal_void;
	y = 0;
	while (y < fractal->height)
	{
		x = 0;
		while (x < fractal->width)
		{
			fractal->real = x;
			fractal->imag = y;
			ft_julia(fractal, c);
			x++;
		}
		y++;
	}
}

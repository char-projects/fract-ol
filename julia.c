/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:56:30 by cschnath          #+#    #+#             */
/*   Updated: 2024/11/23 22:57:19 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
			+ WIDTH / fractal->zoom);
	z.imag = ft_map_to_imag(fractal->imag, fractal->offset_y, fractal->offset_y
			+ HEIGHT / fractal->zoom);
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
	fractal->color = 0x010101 * (i % 256);
	ft_color_pixel(fractal, fractal->real, fractal->imag, fractal->color);
	return (i);
}

void	ft_draw_julia(void *fractal_void)
{
	t_fractal	*fractal;
	t_fractal	c;
	int			x;
	int			y;
	
	fractal = (t_fractal *)fractal_void;
	// This should not be hardcoded - find a way to make it user-defined
	c.real = -0.7;
	c.imag = 0.27015;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			fractal->real = x;
			fractal->imag = y;
			ft_julia(fractal, c);
			x++;
		}
		y++;
	}
}

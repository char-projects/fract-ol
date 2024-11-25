/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:41:43 by cschnath          #+#    #+#             */
/*   Updated: 2024/11/25 14:25:59 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractal	ft_square(t_fractal z)
{
	t_fractal	res;

	res.real = (z.real * z.real) - (z.imag * z.imag);
	res.imag = 2 * z.real * z.imag;
	return (res);
}

int	ft_mandelbrot(t_fractal *fractal, t_fractal c)
{
	int			i;
	t_fractal	z;
	t_fractal	temp_z;

	i = 0;
	fractal->name = "m";
	// Initialize z to the origin
	z.real = 0.0;
    z.imag = 0.0;
	// Iterate while |z|^2 <= 4 and the maximum iteration limit isn't reached
	while (((z.real * z.real) + (z.imag * z.imag)) <= 4 && i < MAX)
	{
		temp_z = z;

		// Calculate z = z^2 + c
		z.real = (temp_z.real * temp_z.real) - (temp_z.imag * temp_z.imag) + c.real;
		z.imag = 2 * temp_z.real * temp_z.imag + c.imag;
		i++;
	}
	// Generate the pixel color based on the base color and iteration count
	unsigned int color_modifier = (i * 0x010101) & 0xFFFFFF; // Gradual fade
	unsigned int pixel_color = fractal->color + color_modifier;

	if (i == MAX)
		ft_color_pixel(fractal, c.real, c.imag, 0x000000);
	else
		ft_color_pixel(fractal, (c.real - fractal->offset_x) * fractal->zoom,
                    (c.imag - fractal->offset_y) * fractal->zoom, pixel_color);
	return (i);
}

void	ft_draw_mandelbrot(void *fractal_void)
{
	t_fractal	*fractal;
	t_fractal	c;
	int			x;
	int			y;

	fractal = (t_fractal *)fractal_void;
	y = 0;
	while (y < fractal->height)
	{
		x = 0;
		while (x < fractal->width)
		{
			c.real = ft_map_to_real(x, fractal->offset_x, fractal->offset_x + fractal->width / fractal->zoom, fractal);
			c.imag = ft_map_to_imag(y, fractal->offset_y, fractal->offset_y + fractal->height / fractal->zoom, fractal);
			ft_mandelbrot(fractal, c);
			x++;
		}
		y++;
	}
}
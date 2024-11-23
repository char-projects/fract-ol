/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:41:43 by cschnath          #+#    #+#             */
/*   Updated: 2024/11/23 15:39:33 by cschnath         ###   ########.fr       */
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

int	ft_mandelbrot(t_fractal fractal, t_fractal c)
{
	int			i;
	t_fractal	z;
	t_fractal	temp_z;

	i = 0;
	// Initialize z to the origin
	z.real = 0.0;
    z.imag = 0.0;
	//c.real = (fractal.real / fractal.zoom) + fractal.offset_x;
	//c.imag = (fractal.imag / fractal.zoom) + fractal.offset_y;
	// Iterate while |z|^2 <= 4 and the maximum iteration limit isn't reached
	while (((z.real * z.real) + (z.imag * z.imag)) <= 4 && i < MAX)
	{
		temp_z = z;

		// Calculate z = z^2 + c
		z.real = (temp_z.real * temp_z.real) - (temp_z.imag * temp_z.imag) + c.real;
		z.imag = 2 * temp_z.real * temp_z.imag + c.imag;
		i++;
	}
	fractal.color = 0xFCBE11 * (i % 256);
	ft_color_pixel(&fractal, (c.real - fractal.offset_x) * fractal.zoom,
                    (c.imag - fractal.offset_y) * fractal.zoom, fractal.color);
	return (i);
}

void	ft_draw_mandelbrot(void *fractal_void)
{
	t_fractal	*fractal;
	t_fractal	c;
	int			x;
	int			y;

	fractal = (t_fractal *)fractal_void;
	fractal->zoom = 200.0; // Adjust to fit the desired view
    fractal->offset_x = -2.0;
    fractal->offset_y = -2.0;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c.real = ft_map_to_real(x, fractal->offset_x, fractal->offset_x + WIDTH / fractal->zoom);
			c.imag = ft_map_to_imag(y, fractal->offset_y, fractal->offset_y + HEIGHT / fractal->zoom);
			ft_mandelbrot(*fractal, c);
			x++;
		}
		y++;
	}
}
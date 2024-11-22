/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:56:30 by cschnath          #+#    #+#             */
/*   Updated: 2024/11/22 15:15:48 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// When it's done, include it in the Makefile
#include "fractol.h"

// This is Mandelbrot - What do I need to change?
int    ft_julia(t_fractal fractal, t_fractal z)
{
    int			i;
	t_fractal	c;
	t_fractal	temp_z;

	i = 0;
	// Initialize z to the origin
	c.real = 0.0;
    c.imag = 0.0;
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

void	ft_draw_julia(void *fractal_void)
{
	(void)fractal_void;
	exit(EXIT_FAILURE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:56:30 by cschnath          #+#    #+#             */
/*   Updated: 2024/11/22 15:45:50 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// So far just a grey window :(
#include "fractol.h"

// C should be constant
int    ft_julia(t_fractal fractal)
{
    int			i;
    t_fractal   c;
	t_fractal	z;
	t_fractal	temp_z;

    c.real = 1.0; // This should not be hardcoded
    c.imag = 1.0;
	i = 0;
	// Initialize z and iterate over every pixel
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
	fractal.color = 0xFCBE11 * (i % 256);
	ft_color_pixel(&fractal, (c.real - fractal.offset_x) * fractal.zoom,
                    (c.imag - fractal.offset_y) * fractal.zoom, fractal.color);
	return (i);
}

void	ft_draw_julia(void *fractal_void)
{
	t_fractal   *fractal;

    fractal = (t_fractal *)fractal_void;
    fractal->real = 0.0;
	fractal->imag = 0.0;
	while (fractal->real < HEIGHT)
	{
		while (fractal->imag < WIDTH)
		{
			ft_julia(*fractal);
			fractal->imag++;
		}
		fractal->real++;
		fractal->imag = 0;
	}
}

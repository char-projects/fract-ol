/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_mandelbrot.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:41:43 by cschnath          #+#    #+#             */
/*   Updated: 2024/11/20 22:55:20 by cschnath         ###   ########.fr       */
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

double	ft_magnitude(t_fractal z)
{
	// Magnitude of z / distance from origin
	return ((z.real * z.real) + (z.imag * z.imag));
}

int	ft_mandelbrot(t_fractal *fractal, t_fractal	c)
{
	int			i;
	t_fractal	z;

	i = 0;
	z.real = 0.0;
    z.imag = 0.0;
	// Iterate suite until:
	// -> Abs(z) >= system's max value
	// -> Number of iterations is too high (infinite loop)
	while (ft_magnitude(z) <= 4 && i < MAX)
	{
		z = ft_square(z);
		z.real += c.real;
		z.imag += c.imag;
		i++;
	}
	fractal->real = c.real;
	fractal->imag = c.imag;
	// If max iteration, color the pixel black
	if (i == MAX)
		ft_color_pixel(fractal, z.real, z.imag, 0x000000);
	// Else, multiply the color by the number of iterations
	else
	{
		fractal->color = 0x010101 * (i % 255);
		ft_color_pixel(fractal, z.real, z.imag, fractal->color * (i / (double)MAX));
	}
	return (i);
}

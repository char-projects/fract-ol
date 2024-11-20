/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_mandelbrot.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:41:43 by cschnath          #+#    #+#             */
/*   Updated: 2024/11/20 15:27:29 by cschnath         ###   ########.fr       */
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
	// Initialize real and imag to avoid undefined behavior
	z.real = 0.0;
	z.imag = 0.0;
	// c constants are set to the coordinates of the pixel - HOW?
	// fractal->c = x.y;
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
	// draw_random(0, 0, fractal);
	// If max iteration, color the pixel black
	if (i == MAX)
		ft_color_pixel(fractal, 0x000000);
	// Else, multiply the color by the number of iterations
	else
		ft_color_pixel(fractal, (fractal->color * i));
	return (i);
}

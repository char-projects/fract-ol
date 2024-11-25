/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:41:43 by cschnath          #+#    #+#             */
/*   Updated: 2024/11/25 18:37:18 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mandelbrot(t_fractal *fractal)
{
	int			i;
	double		temp_z;

	i = 0;
	fractal->name = "m";
	// Initialize z to the origin
	fractal->z_real = 0.0;
    fractal->z_imag = 0.0;
	fractal->c_real = (fractal->real / fractal->zoom) + fractal->offset_x;
	fractal->c_imag = (fractal->imag / fractal->zoom) + fractal->offset_y;
	// Iterate while |z|^2 <= 4 and the maximum iteration limit isn't reached
	while (++i < fractal->max)
	{
		temp_z = fractal->z_real * fractal->z_real - fractal->z_imag * fractal->z_imag
			+ fractal->c_real;
		fractal->z_imag = 2.0 * fractal->z_real * fractal->z_imag + fractal->c_imag;
		fractal->z_real = temp_z;
		if (fractal->z_real * fractal->z_real + fractal->z_imag
			* fractal->z_imag >= 4.0)
			break ;
	}
	if (i == fractal->max)
		ft_color_pixel(fractal, fractal->real, fractal->imag, 0x000000);
	else
		ft_color_pixel(fractal, fractal->real, fractal->imag, (fractal->color * i));
	return (i);
}

void	*ft_draw_mandelbrot(void *void_pointer)
{
	t_fractal *fractal;
	
	fractal = (t_fractal *)void_pointer;
	fractal->real = 0;
	fractal->imag = 0;
	while (fractal->real < fractal->width)
	{
		while (fractal->imag < fractal->height)
		{
			ft_mandelbrot(fractal);
			fractal->imag++;
		}
		fractal->real++;
		fractal->imag = 0;
	}
	return (NULL);
}
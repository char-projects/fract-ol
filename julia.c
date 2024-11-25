/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:56:30 by cschnath          #+#    #+#             */
/*   Updated: 2024/11/25 18:48:53 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Function to generate a random double
double	ft_make_random(void)
{
	return (((double)rand() / RAND_MAX) * 3.0 - 1.5);
}

void	ft_random_julia(double *c_real, double *c_imag)
{
	*c_real = ft_make_random();
	*c_imag = ft_make_random();
}

// C should be constant
void	ft_julia(t_fractal *fractal)
{
	int		i;
	double	temp_z;

	i = 0;
	fractal->name = "j";
	// Initialize z and iterate over every pixel
	fractal->z_real = fractal->real / fractal->zoom + fractal->offset_x;
	fractal->z_imag = fractal->imag / fractal->zoom + fractal->offset_y;
	// Iterate while |z|^2 <= 4 and the maximum iteration limit isn't reached
	while (++i < fractal->max)
	{
		temp_z = fractal->z_real;
		// Calculate z = z^2 + c
		fractal->z_real = fractal->z_real * fractal->z_real - fractal->z_imag
				* fractal->z_imag + fractal->c_real;
		fractal->z_imag = 2.0 * fractal->z_imag * temp_z + fractal->c_imag;
		if (fractal->z_real * fractal->z_real + fractal->z_imag
			* fractal->z_imag >= 4.0)
			break ;
	}
	if (i == fractal->max)
		ft_color_pixel(fractal, fractal->real, fractal->imag, 0x000000);
	else
		ft_color_pixel(fractal, fractal->real, fractal->imag, (fractal->color * (i % 255)));
}

void	ft_draw_julia(t_fractal *fractal)
{
	fractal->real = 0;
	fractal->imag = 0;
	while (fractal->real < fractal->width)
	{
		while (fractal->imag < fractal->height)
		{
			ft_julia(fractal);
			fractal->imag++;
		}
		fractal->real++;
		fractal->imag = 0;
	}
}

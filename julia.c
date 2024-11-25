/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:56:30 by cschnath          #+#    #+#             */
/*   Updated: 2024/11/25 22:41:08 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

double	ft_make_random(void)
{
	return (((double)rand() / RAND_MAX) * 3.0 - 1.5);
}

void	ft_random_julia(double *c_real, double *c_imag)
{
	*c_real = ft_make_random();
	*c_imag = ft_make_random();
}

void	ft_julia(t_fractal *fractal)
{
	int		i;
	double	temp_z;

	i = 0;
	fractal->name = "j";
	fractal->z_real = fractal->r / fractal->zoom + fractal->offset_x;
	fractal->z_imag = fractal->i / fractal->zoom + fractal->offset_y;
	while (++i < fractal->max)
	{
		temp_z = fractal->z_real;
		fractal->z_real = fractal->z_real * fractal->z_real - fractal->z_imag
			* fractal->z_imag + fractal->c_real;
		fractal->z_imag = 2 * fractal->z_imag * temp_z + fractal->c_imag;
		if (fractal->z_real * fractal->z_real + fractal->z_imag
			* fractal->z_imag >= 4.0)
			break ;
	}
	if (i == fractal->max)
		ft_color_pixel(fractal, fractal->r, fractal->i, 0x000000);
	else
		ft_color_pixel(fractal, fractal->r, fractal->i, (fractal->color * (i
					% 255)));
}

void	ft_draw_julia(t_fractal *fractal)
{
	fractal->r = 0;
	fractal->i = 0;
	while (fractal->r < fractal->width)
	{
		while (fractal->i < fractal->height)
		{
			ft_julia(fractal);
			fractal->i++;
		}
		fractal->r++;
		fractal->i = 0;
	}
}

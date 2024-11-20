/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:43:22 by cschnath          #+#    #+#             */
/*   Updated: 2024/11/20 22:43:05 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_draw_mandelbrot(void *fractal_void)
{
	ft_printf("Drawing Mandelbrot...\n");
	t_fractal	*fractal;
	t_fractal	c;
	int			x;
	int			y;

	fractal = (t_fractal *)fractal_void;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c.real = ft_map_to_real(x, -2.0, 2.0);
			c.imag = ft_map_to_imag(y, -2.0, 2.0);
			ft_mandelbrot(fractal, c);
			x++;
		}
		y++;
	}
	ft_printf("Finished drawing Mandelbrot\n");
}

void	ft_color_pixel(t_fractal *fractal, int x, int y, int color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		mlx_put_pixel(fractal->pic, x, y, color);
		ft_printf("Coloring pixel at (%d, %d) with color %x\n", x, y, color);
	}	
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:43:22 by cschnath          #+#    #+#             */
/*   Updated: 2024/11/21 21:50:34 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Change color OUTSIDE of fractal to something other than black

#include "fractol.h"

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

void	ft_draw_julia(void *fractal_void)
{
	(void)fractal_void;
	exit(EXIT_FAILURE);
}

void	ft_color_pixel(t_fractal *fractal, int x, int y, int color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		mlx_put_pixel(fractal->pic, x, y, color);
}

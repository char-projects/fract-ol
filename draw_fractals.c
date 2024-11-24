/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:43:22 by cschnath          #+#    #+#             */
/*   Updated: 2024/11/24 21:37:55 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Build something that changes the colors

#include "fractol.h"

void	ft_zoom(t_fractal *fractal, int x, int y, int zoom)
{
	double	scale;

	scale = 1.5;
	if (zoom == 1)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x
				/ (fractal->zoom * scale));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y
				/ (fractal->zoom * scale));
		fractal->zoom *= scale;
	}
	else if (zoom == -1)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x
				/ (fractal->zoom / scale));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y
				/ (fractal->zoom / scale));
		fractal->zoom /= scale;
	}
	ft_which_fractal(fractal, fractal->name);
}

void	ft_color_pixel(t_fractal *fractal, int x, int y, int color)
{
	if (x >= 0 && x < fractal->width && y >= 0 && y < fractal->height)
		mlx_put_pixel(fractal->pic, x, y, color);
}

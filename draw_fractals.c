/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:43:22 by cschnath          #+#    #+#             */
/*   Updated: 2024/11/22 14:21:34 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Change color OUTSIDE of fractal to something other than black

#include "fractol.h"

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

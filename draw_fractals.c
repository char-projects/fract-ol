/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:43:22 by cschnath          #+#    #+#             */
/*   Updated: 2024/11/18 23:57:56 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractal(t_fractal *fractal)
{
	fractal->real = 0;
	fractal->imag = 0;
	fractal->color = 0xFCBE11; // Should be orange
}

void	ft_draw_mandelbrot(void *fractal_void)
{
	t_fractal	*fractal;
	t_fractal	c;
	int			x;
	int			y;

	fractal = (t_fractal *)fractal_void;
	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			c.real = ft_map_to_real(x, -2.0, 2.0);
			c.imag = ft_map_to_imag(y, -2.0, 2.0);
			ft_mandelbrot(fractal, c);
			x++;
		}
		y++;
	}
}

/* Just a test
void	draw_random(int x, int y, t_fractal *fractal)
{
	ft_printf("5. Reached draw random\n");
	fractal->picture = malloc(sizeof(fractal));
	while (x < WIDTH)
	{
		while (y < HEIGHT)
		{
			mlx_put_pixel(fractal->picture, x, y, 0xFFFFA500);
			y++;
		}
		x++;
	}
} */
// Change this useless function
void	ft_color_pixel(t_fractal *fractal, int color)
{
	(void)fractal;
	(void)color;
}

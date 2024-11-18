/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 04:20:39 by cschnath          #+#    #+#             */
/*   Updated: 2024/11/18 23:56:37 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// This function closes the window when you press the escape key
void	ft_esc_win(mlx_key_data_t keydata, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(fractal->mlx);
		exit(EXIT_SUCCESS);
	}
}

void	ft_mlx_error(void)
{
	ft_printf("Error creating the window\n");
	exit(EXIT_FAILURE);
}

// Initialize MLX - This opens the window
void	ft_init_win(t_fractal *fractal)
{
	fractal->mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true);
	if (!fractal->mlx)
		ft_mlx_error();
	/* fractal->path = "test.png";
	mlx_texture_t *texture = mlx_load_png(fractal->path);
	if (!texture)
		ft_mlx_error();
	fractal->picture = mlx_texture_to_image(fractal->mlx, texture);
	if (!fractal->picture)
		ft_mlx_error();
	if (mlx_image_to_window(fractal->mlx, fractal->picture, 1, 1))
		ft_mlx_error(); */
	mlx_key_hook(fractal->mlx, ft_esc_win, fractal);
	mlx_loop_hook(fractal->mlx, ft_draw_mandelbrot, fractal);
	mlx_loop(fractal->mlx);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 04:20:39 by cschnath          #+#    #+#             */
/*   Updated: 2024/11/21 20:18:56 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Closes window when ESC is pressed - Done
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

// Done
void	ft_mlx_error(void)
{
	ft_printf("Error creating the window\n");
	exit(EXIT_FAILURE);
}

// Initialize MLX - Done, I think
void	ft_init_win(t_fractal *fractal)
{
	fractal->mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true);
	if (!fractal->mlx)
		ft_mlx_error();
	fractal->pic = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->pic)
		ft_mlx_error();
	if (mlx_image_to_window(fractal->mlx, fractal->pic, 0.0, 0.0) < 0.0)
		ft_mlx_error();
	ft_draw_mandelbrot(fractal);
	mlx_key_hook(fractal->mlx, ft_esc_win, fractal);
	mlx_loop(fractal->mlx);
}
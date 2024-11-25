/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 04:20:39 by cschnath          #+#    #+#             */
/*   Updated: 2024/11/25 20:44:14 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Done
void	ft_change_max(t_fractal *fractal, int key_code)
{
	if (key_code == 3)
	{
		if (fractal->max > 5000)
			fractal->max -= 600;
	}
	else if (key_code == 4)
	{
		if (fractal->max < 5000)
			fractal->max += 600;
	}
}

void	ft_keys(mlx_key_data_t keys, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	if (keys.key == MLX_KEY_ESCAPE)
		ft_exit_fractal(fractal);
	else if ((keys.key == MLX_KEY_LEFT || keys.key == MLX_KEY_A))
		fractal->offset_x -= 50 / fractal->zoom;
	else if ((keys.key == MLX_KEY_RIGHT || keys.key == MLX_KEY_D))
		fractal->offset_x += 50 / fractal->zoom;
	else if ((keys.key == MLX_KEY_UP || keys.key == MLX_KEY_W))
		fractal->offset_y -= 50 / fractal->zoom;
	else if ((keys.key == MLX_KEY_DOWN || keys.key == MLX_KEY_S))
		fractal->offset_y += 50 / fractal->zoom;
	else if (keys.key == MLX_KEY_C && keys.action == MLX_PRESS)
		fractal->color += (255 * 255 * 255) / 100;
	else if (keys.key == MLX_KEY_J && keys.action == MLX_PRESS)
		ft_random_julia(&fractal->c_real, &fractal->c_imag);
	else if (keys.key == MLX_KEY_N && keys.action == MLX_PRESS)
		ft_change_max(fractal, 3);
	else if (keys.key == MLX_KEY_M && keys.action == MLX_PRESS)
		ft_change_max(fractal, 4);
	ft_which_fractal(fractal, fractal->name);
}

// This one is just personal preference
void	ft_resize_win(int32_t width, int32_t height, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	if (fractal->pic)
		mlx_delete_image(fractal->mlx, fractal->pic);
	fractal->width = width;
	fractal->height = height;
	fractal->pic = mlx_new_image(fractal->mlx, width, height);
	if (!fractal->pic)
		ft_mlx_error();
	if (mlx_image_to_window(fractal->mlx, fractal->pic, 0, 0) < 0)
		ft_mlx_error();
	ft_which_fractal(fractal, fractal->name);
}

// Error message - Done
void	ft_mlx_error(void)
{
	ft_printf("Error creating the window\n");
	exit(EXIT_FAILURE);
}

// Initialize MLX - Done
void	ft_init_win(t_fractal *fractal, char *type, char *p1, char *p2)
{
	fractal->mlx = mlx_init(fractal->width, fractal->height, "fract-ol", true);
	if (!fractal->mlx)
		ft_mlx_error();
	// Get window size here and store it in size?
	fractal->pic = mlx_new_image(fractal->mlx, fractal->width, fractal->height);
	if (!fractal->pic)
		ft_mlx_error();
	if (mlx_image_to_window(fractal->mlx, fractal->pic, 0.0, 0.0) < 0.0)
		ft_mlx_error();
	if (ft_strncmp(type, "m", 1) == 0 || ft_strncmp(type, "b", 1) == 0)
		ft_which_fractal(fractal, type);
	else
		ft_init_julia(fractal, p1, p2);
	mlx_key_hook(fractal->mlx, ft_keys, fractal);
	mlx_scroll_hook(fractal->mlx, ft_scroll, fractal);
	mlx_resize_hook(fractal->mlx, ft_resize_win, fractal);
	// mlx_mouse_hook(fractal->mlx, ft_mouse, fractal);
	mlx_loop(fractal->mlx);
	ft_exit_fractal(fractal);
}
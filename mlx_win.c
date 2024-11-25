/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 04:20:39 by cschnath          #+#    #+#             */
/*   Updated: 2024/11/25 14:19:22 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	else if (keys.key == MLX_KEY_J && keys.action == MLX_PRESS)
	{
		ft_random_julia(fractal);
		ft_draw_julia(fractal, 1);
	}
	else if (keys.key == MLX_KEY_C && keys.action == MLX_PRESS)
	{
		fractal->current_scheme = (fractal->current_scheme + 1) % 5;
		fractal->color = fractal->color_schemes[fractal->current_scheme];
	}
	ft_which_fractal(fractal, fractal->name, 0);
}
/*
int	ft_mouse(int button, int x, int y, t_fractal *fractal)
{
	double	x;
	double	y;

	x = (double)x / fractal->width;
	y = (double)y / fractal->height;
	if (button == M_ZOOM_IN)
	{
		fractal->zoom *= ZOOM;
		ft_bullseye(fractal, x, y);
	}
	else if (button == M_ZOOM_OUT)
	{
		fractal->zoom /= ZOOM;
		ft_bullseye(fractal, x, y);
	}
	ft_init_fractol(fractal);
	return (0);
}

void	ft_bullseye(t_fractal *fractal, double x, double y)
{
	if (ft_strncmp(fractal->name, "j", 1) == 0)
		ft_julia_zoom(fract, x, y);
	else
	{
		fract->offset_x = (x - 0.5)
			* ((MAX_REAL - MIN_REAL) / fract->zoom) + fract->offset_x;
		fract->shift_i = (y - 0.5)
			* ((MAX_IM - MIN_IM) / fract->zoom) + fract->shift_i;
	}
}

void	ft_julia_zoom(t_fractal *fractal, double x, double y)
{
	fractal->offset_x = (x - 0.5)
		* ((2.0 - -2.0) / fract->zoom) + fract->offset_x;
	fractal->shift_i = (y - 0.5)
		* ((2.0 - -2.0) / fract->zoom) + fract->shift_i;
}
*/
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
	ft_which_fractal(fractal, fractal->name, 1);
}

// Error message - Done
void	ft_mlx_error(void)
{
	ft_printf("Error creating the window\n");
	exit(EXIT_FAILURE);
}

// Initialize MLX - Done
void	ft_init_win(t_fractal *fractal, char *type)
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
	ft_which_fractal(fractal, type, 0);
	mlx_key_hook(fractal->mlx, ft_keys, fractal);
	mlx_scroll_hook(fractal->mlx, ft_scroll, fractal);
	mlx_resize_hook(fractal->mlx, ft_resize_win, fractal);
	// mlx_mouse_hook(fractal->mlx, ft_mouse, fractal);
	mlx_loop(fractal->mlx);
	ft_exit_fractal(fractal);
}
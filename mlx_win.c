/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 04:20:39 by cschnath          #+#    #+#             */
/*   Updated: 2024/11/24 15:35:48 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Fix Memory Leaks!!
Allocated resources (e.g., mlx_image_t) are never freed
*/

#include "fractol.h"

// Remove MLX_PRESS if you want to zoom continously and not just once
void	ft_keys(mlx_key_data_t keys, void *param)
{
	t_fractal	*fractal;
	t_fractal	c;
	
	fractal = (t_fractal *)param;
	c.real = -0.7;
	c.imag = 0.27015;
	if (keys.key == MLX_KEY_ESCAPE)
		ft_exit_fractal(fractal);
	else if ((keys.key == MLX_KEY_LEFT || keys.key == MLX_KEY_A)
		&& keys.action == MLX_PRESS)
		fractal->offset_x -= 100 / fractal->zoom;
	else if ((keys.key == MLX_KEY_RIGHT || keys.key == MLX_KEY_D)
		&& keys.action == MLX_PRESS)
		fractal->offset_x += 100 / fractal->zoom;
	else if ((keys.key == MLX_KEY_UP || keys.key == MLX_KEY_W)
		&& keys.action == MLX_PRESS)
		fractal->offset_y -= 100 / fractal->zoom;
	else if ((keys.key == MLX_KEY_DOWN || keys.key == MLX_KEY_S)
		&& keys.action == MLX_PRESS)
		fractal->offset_y += 100 / fractal->zoom;
	else if (keys.key == MLX_KEY_J)
		ft_random_julia(&c.real, &c.imag);
	ft_which_fractal(fractal, fractal->name);
}

void	ft_scroll(double up, double down, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	(void)up;
	if (down > 0)
		ft_zoom(fractal, up, down, 1);
	else if (down < 0)
		ft_zoom(fractal, up, down, -1);
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
	ft_which_fractal(fractal, type);
	mlx_key_hook(fractal->mlx, ft_keys, fractal);
	mlx_scroll_hook(fractal->mlx, ft_scroll, fractal);
	mlx_resize_hook(fractal->mlx, ft_resize_win, fractal);
	mlx_loop(fractal->mlx);
	ft_exit_fractal(fractal);
}
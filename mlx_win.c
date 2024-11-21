/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 04:20:39 by cschnath          #+#    #+#             */
/*   Updated: 2024/11/21 22:19:42 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Fix Memory Leaks!!
Allocated resources (e.g., mlx_image_t) are never freed
*/

#include "fractol.h"

/* Assign keys to zoom
void	ft_zoom()
{
	
} */

// Closes window when ESC is pressed - Done
void	ft_esc_win(mlx_key_data_t keydata, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(fractal->mlx);
		mlx_delete_image(fractal->mlx, fractal->pic);
		exit(EXIT_FAILURE);
	}
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
	fractal->mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true);
	if (!fractal->mlx)
		ft_mlx_error();
	fractal->pic = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->pic)
		ft_mlx_error();
	if (mlx_image_to_window(fractal->mlx, fractal->pic, 0.0, 0.0) < 0.0)
		ft_mlx_error();
	ft_which_fractal(fractal, type);
	mlx_key_hook(fractal->mlx, ft_esc_win, fractal);
	mlx_loop(fractal->mlx);
	mlx_delete_image(fractal->mlx, fractal->pic);
}
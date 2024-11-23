/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:29:25 by cschnath          #+#    #+#             */
/*   Updated: 2024/11/24 00:45:03 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// I feel like at this point the valgrind errors are coming from the MLX
void	ft_exit_fractal(t_fractal *fractal)
{
	mlx_delete_image(fractal->mlx, fractal->pic);
	mlx_close_window(fractal->mlx);
	free(fractal->mlx);
	exit(1);
}

void	ft_init_fractal(t_fractal *fractal)
{
	fractal->real = 0.0;
	fractal->imag = 0.0;
	fractal->color = 0xFCBE11; // Should be orange but it's not
	fractal->zoom = 150;
	fractal->offset_x = -1.21;
	fractal->offset_y = -1.21;
	fractal->pic = NULL;
	fractal->tex = NULL;
	fractal->mlx = NULL;
}

// Choose fractal type depending on argv[1] - Done
void	ft_which_fractal(t_fractal *fractal, char *type)
{
	if (ft_strncmp(type, "m", 1) == 0)
		ft_draw_mandelbrot(fractal);
	else if (ft_strncmp(type, "j", 1) == 0)
		ft_draw_julia(fractal);
	else if (ft_strncmp(type, "b", 1) == 0)
		ft_draw_burningship(fractal);
	else
	{
		ft_printf("Fractal type not supported!\n");
		ft_exit_fractal(fractal);
	}
}

// Done
int	main(int argc, char *argv[])
{
	t_fractal	fractal;

	if (argc != 2)
	{
		ft_printf("Usage: ./fractol <fractal>\n");
		ft_printf("Available fractals:");
		ft_printf(" mandelbrot(m), julia(j), burningship(b)\n");
		return (1);
	}
	// Free fractal later!!
	ft_init_fractal(&fractal);
	ft_init_win(&fractal, argv[1]);
}

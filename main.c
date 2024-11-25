/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:29:25 by cschnath          #+#    #+#             */
/*   Updated: 2024/11/25 18:31:34 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// I feel like at this point the valgrind errors are coming from the MLX
void	ft_exit_fractal(t_fractal *fractal)
{
	mlx_delete_image(fractal->mlx, fractal->pic);
	mlx_close_window(fractal->mlx);
	mlx_terminate(fractal->mlx);
	free(fractal);
	exit(1);
}

void	ft_init_fractal(t_fractal *fractal)
{
	fractal->real = 0;
	fractal->imag = 0;
	fractal->color = 0xD8BFD8; // Should be orange but it's not
	fractal->zoom = 150;
	fractal->offset_x = -2.5;
	fractal->offset_y = -2.0;
	fractal->pic = NULL;
	fractal->tex = NULL;
	fractal->mlx = NULL;
	fractal->width = 800;
	fractal->height = 600;
	fractal->max = 50;
}

void	ft_change_max(t_fractal *fractal, int key_code)
{
	if (key_code == 3)
	{
		if (fractal->max > 5000)
			fractal->max -= 50;
	}
	else if (key_code == 4)
	{
		if (fractal->max < 5000)
			fractal->max += 50;
	}
}

// Choose fractal type depending on argv[1]
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
	t_fractal	*fractal;

	if (argc != 2)
	{
		ft_printf("Usage: ./fractol <fractal>\n");
		ft_printf("Available fractals:");
		ft_printf(" mandelbrot(m), julia(j), burningship(b)\n");
		return (1);
	}
	fractal = malloc(sizeof(t_fractal));
	ft_init_fractal(fractal);
	ft_init_win(fractal, argv[1]);
}

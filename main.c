/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:29:25 by cschnath          #+#    #+#             */
/*   Updated: 2024/11/21 21:10:19 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Fix Memory Leaks:
Allocated resources (e.g., mlx_image_t) are never freed
Use mlx_delete_image() and other MLX42 cleanup functions
in ft_esc_win and at program termination
*/

#include "fractol.h"

void	ft_init_fractal(t_fractal *fractal)
{
	fractal->real = 0.0;
	fractal->imag = 0.0;
	fractal->color = 0xFCBE11; // Should be orange
	fractal->zoom = 300;
	fractal->offset_x = -1.21;
	fractal->offset_y = -1.21;
	fractal->pic = NULL;
	fractal->tex = NULL;
	fractal->mlx = NULL;
	
}

void	ft_which_fractal(t_fractal *fractal, char *type)
{
	if (ft_strncmp(type, "m", 1) == 0)
		ft_draw_mandelbrot(fractal);
	/*
	else if (ft_strncmp(type, "j", 1) == 0)
		ft_julia(fractal);
	else if (ft_strncmp(type, "b", 1) == 0)
		ft_burningship(fractal);
	*/
	else
	{
		ft_printf("Fractal type not supported!\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char *argv[])
{
	t_fractal	fractal;

	if (argc != 2)
	{
		ft_printf("Usage: ./fractol <fractal>\n");
		ft_printf("Available fractals:");
		ft_printf(" mandelbrot(m), julia(j), burningship(b)\n");
		return (EXIT_FAILURE);
	}
	// Free fractal later!!
	ft_init_fractal(&fractal);
	ft_init_win(&fractal);
	ft_which_fractal(&fractal, argv[1]);
	return (EXIT_SUCCESS);
}

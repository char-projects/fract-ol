/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:29:25 by cschnath          #+#    #+#             */
/*   Updated: 2024/11/18 23:56:25 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	which_fractal(t_fractal *fractal, char *type)
{
	t_fractal c;
	if (ft_strncmp(type, "m", 1) == 0)
		ft_mandelbrot(fractal, c);
	/*
	else if (ft_strncmp(type, "j", 1) == 0)
		ft_julia(fractal);
	else if (ft_strncmp(type, "b", 1) == 0)
		ft_burningship(fractal);
	*/
}

int	main(int argc, char *argv[])
{
	t_fractal	*fractal;

	if (argc != 2)
	{
		ft_printf("Usage: ./fractol <fractal>\n");
		ft_printf("Available fractals:");
		ft_printf(" mandelbrot(m), julia(j), burningship(b)\n");
		return (0);
	}
	// Free fractal later!!
	fractal = malloc(sizeof(t_fractal));
	ft_init_win(fractal);
	which_fractal(fractal, argv[1]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_real.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 09:40:43 by cschnath          #+#    #+#             */
/*   Updated: 2024/11/24 15:39:51 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Iterate through the pixels of the window
// Calls appropriate function to draw the fractal

#include "fractol.h"

double	ft_map_to_real(int x, double min_r, double max_r, t_fractal *fractal)
{
	return (min_r + ((double)x / (fractal->width - 1)) * (max_r - min_r));
}

double	ft_map_to_imag(int y, double min_i, double max_i, t_fractal *fractal)
{
	return (min_i + ((double)y / (fractal->height - 1)) * (max_i - min_i));
}

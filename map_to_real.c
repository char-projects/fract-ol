/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_real.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 09:40:43 by cschnath          #+#    #+#             */
/*   Updated: 2024/11/21 21:12:45 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Iterate through the pixels of the window
// Calls appropriate function to draw the fractal

#include "fractol.h"

double	ft_map_to_real(int x, double min_r, double max_r)
{
	return (x * (max_r - min_r) / WIDTH + min_r);
}

// This runs in an infinite loop - FIX IT!!!
double	ft_map_to_imag(int y, double min_i, double max_i)
{
	return (y * (max_i - min_i) / HEIGHT + min_i);
}

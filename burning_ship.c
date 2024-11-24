/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 00:06:07 by cschnath          #+#    #+#             */
/*   Updated: 2024/11/24 22:01:24 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:13:49 by ssottori          #+#    #+#             */
/*   Updated: 2024/05/01 16:13:52 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_burningship(t_fractal *fractal, double real, double imag)
{
	int			i;
	t_fractal	z;
	double		temp_z;

	i = 0;
	fractal->name = "b";
	z.real = 0.0;
	z.imag = 0.0;
	fractal->offset_x = -2.0;
	fractal->offset_y = -2.0;
	while ((z.real * z.real + z.imag * z.imag <= 4) && i < MAX)
	{
		temp_z = z.real * z.real - z.imag * z.imag + real;
		z.imag = fabs(2.0 * z.real * z.imag) + imag;
		z.real = fabs(temp_z);
		i++;
	}
	return (i);
}

void ft_draw_burningship(void *fractal_void)
{
    t_fractal *fractal = (t_fractal *)fractal_void;
    int x, y, iteration;
    double real, imag;
    int color;

    y = 0;
    while (y < fractal->height)
    {
        x = 0;
        while (x < fractal->width)
        {
            // Map screen coordinates to the complex plane
            real = ft_map_to_real(x, fractal->offset_x,
                fractal->offset_x + fractal->width / fractal->zoom, fractal);
            imag = ft_map_to_imag(y, fractal->offset_y,
                fractal->offset_y + fractal->height / fractal->zoom, fractal);

            // Compute burning ship fractal iterations
            iteration = ft_burningship(fractal, real, imag);

            // Compute color based on iteration
            if (iteration == MAX)
                color = 0x000000; // Black for points inside the set
            else
                color = 0xD8BFD8 * (iteration % MAX); // Gradient for points outside

            // Draw the pixel
            ft_color_pixel(fractal, x, y, color);

            x++;
        }
        y++;
    }
}


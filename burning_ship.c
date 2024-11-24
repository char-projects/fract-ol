/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 00:06:07 by cschnath          #+#    #+#             */
/*   Updated: 2024/11/24 22:55:31 by cschnath         ###   ########.fr       */
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

int	ft_burningship(t_fractal *fractal, t_fractal c)
{
	int			i;
	t_fractal	z;
	double		temp_z;

	i = 0;
	fractal->name = "b";
	z.real = 0.0;
	z.imag = 0.0;
	while ((z.real * z.real + z.imag * z.imag <= 4) && i < MAX)
	{
		temp_z = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = fabs(2.0 * z.real * z.imag) + c.imag;
		z.real = fabs(temp_z);
		i++;
	}
    // Generate the pixel color based on the base color and iteration count
	unsigned int color_modifier = (i * 0x010101) & 0xFFFFFF; // Gradual fade
	unsigned int pixel_color = fractal->color + color_modifier;

	if (i == MAX)
		ft_color_pixel(fractal, c.real, c.imag, 0x000000);
	else
		ft_color_pixel(fractal, (c.real - fractal->offset_x) * fractal->zoom,
                    (c.imag - fractal->offset_y) * fractal->zoom, pixel_color);
	return (i);
}

void	ft_draw_burningship(void *fractal_void)
{
	t_fractal	*fractal;
    t_fractal   c;
	int			x;
	int			y;

	fractal = (t_fractal *)fractal_void;
	fractal->offset_x = -2.0;
	fractal->offset_y = -2.0;
	x = 0;
	y = 0;
	while (x < fractal->width)
	{
		while (y < fractal->height)
		{
			c.real = ft_map_to_real(x, fractal->offset_x, fractal->offset_x + fractal->width / fractal->zoom, fractal);
			c.imag = ft_map_to_imag(y, fractal->offset_y, fractal->offset_y + fractal->height / fractal->zoom, fractal);
            ft_burningship(fractal, c);
			y++;
		}
		x++;
		y = 0;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:42:08 by cschnath          #+#    #+#             */
/*   Updated: 2024/11/21 22:03:15 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define MAX 500
# define WIDTH 800
# define HEIGHT 600

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>

typedef struct s_fractal
{
	double			imag; // y axis
	double			real; // x axis
	double			tmp_i;
	double			tmp_r;
	double			zoom;
	double			offset_x;
	double			offset_y;
	mlx_image_t		*pic;
	mlx_texture_t	*tex;
	mlx_t			*mlx;
	int				color;
	const char		*path;
}					t_fractal;

// Calculate Mandelbrot
t_fractal			ft_square(t_fractal z);
int					ft_mandelbrot(t_fractal fractal, t_fractal c);

// Map to real
double				ft_map_to_real(int x, double min_real, double max_real);
double				ft_map_to_imag(int y, double min_imag, double max_imag);

// Main
void				ft_which_fractal(t_fractal *fractal, char *type);
void				ft_init_fractal(t_fractal *fractal);

// MLX window
void				ft_esc_win(mlx_key_data_t keydata, void *param);
void				ft_init_win(t_fractal *fractal, char *type);
void				ft_mlx_error(void);

// Draw fractal
void				ft_draw_mandelbrot(void *fractal_void);
void				ft_draw_julia(void *fractal_void);
void				ft_color_pixel(t_fractal *fractal, int x, int y, int color);

#endif

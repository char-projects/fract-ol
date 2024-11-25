/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:42:08 by cschnath          #+#    #+#             */
/*   Updated: 2024/11/25 18:48:33 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>

typedef struct s_fractal
{
	double 			imag; // y axis
	double			real; // x axis
	double			z_real;
	double			z_imag;
	double			c_real;
	double			c_imag;
	double			zoom;
	double			offset_x;
	double			offset_y;
	mlx_image_t		*pic;
	mlx_texture_t	*tex;
	mlx_t			*mlx;
	int				color;
	int				width;
	int				height;
	int				max;
	char			*name;
	const char		*path;
}					t_fractal;

// Mandelbrot
int					ft_mandelbrot(t_fractal *fractal);
void				*ft_draw_mandelbrot(void *void_pointer);

// Main
void				ft_exit_fractal(t_fractal *fractal);
void				ft_which_fractal(t_fractal *fractal, char *type);
void				ft_init_fractal(t_fractal *fractal);
void				ft_change_max(t_fractal *fractal, int key_code);

// MLX window
void				ft_keys(mlx_key_data_t keydata, void *param);
void				ft_init_win(t_fractal *fractal, char *type);
void				ft_mlx_error(void);
// void				ft_mouse(mlx_mousefunc mouse, void *param);

// Draw fractals
void				ft_zoom(t_fractal *fractal, int x, int y, int zoom);
void				ft_color_pixel(t_fractal *fractal, int x, int y, int color);
void				ft_scroll(double up, double down, void *param);

// Julia
double				ft_make_random(void);
void				ft_random_julia(double *c_real, double *c_imag);
void				ft_draw_julia(t_fractal	*fractal);
void				ft_julia(t_fractal *fractal);

// Burning ship
int					ft_burningship(t_fractal *fractal);
void				ft_draw_burningship(t_fractal *fractal);

#endif

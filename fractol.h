/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:42:08 by cschnath          #+#    #+#             */
/*   Updated: 2024/11/24 00:46:35 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define MAX 500
// Height and width probably shouldn't be hardcoded
// Maybe I can find an MLX function to adjust the window size
# define WIDTH 800
# define HEIGHT 600

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>

typedef struct s_fractal
{
	double imag; // y axis
	double real; // x axis
	double			tmp_i;
	double			tmp_r;
	double			zoom;
	double			offset_x;
	double			offset_y;
	mlx_image_t		*pic;
	mlx_texture_t	*tex;
	mlx_t			*mlx;
	int				color;
	char			*name;
	const char		*path;
}					t_fractal;

// Mandelbrot
t_fractal			ft_square(t_fractal z);
int					ft_mandelbrot(t_fractal *fractal, t_fractal c);
void				ft_draw_mandelbrot(void *fractal_void);

// Map to real
double				ft_map_to_real(int x, double min_real, double max_real);
double				ft_map_to_imag(int y, double min_imag, double max_imag);

// Main
void				ft_exit_fractal(t_fractal *fractal);
void				ft_which_fractal(t_fractal *fractal, char *type);
void				ft_init_fractal(t_fractal *fractal);

// MLX window
void				ft_keys(mlx_key_data_t keydata, void *param);
void				ft_init_win(t_fractal *fractal, char *type);
void				ft_mlx_error(void);

// Draw fractals
void				ft_zoom(t_fractal *fractal, int x, int y, int zoom);
void				ft_color_pixel(t_fractal *fractal, int x, int y, int color);

// Julia
void				ft_random_julia(double *real, double *imag);
void				ft_draw_julia(void *fractal_void);
int					ft_julia(t_fractal *fractal, t_fractal c);

// Burning ship
int					ft_burningship(t_fractal *fractal, t_fractal c);
void				ft_draw_burningship(void *fractal_void);

#endif

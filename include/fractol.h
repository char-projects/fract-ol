/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:42:08 by cschnath          #+#    #+#             */
/*   Updated: 2024/11/25 22:40:37 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/include/libft.h"
# include <fcntl.h>
# include <math.h>

typedef struct s_fractal
{
	double		i; // y axis
	double		r; // x axis
	double		z_real;
	double		z_imag;
	double		c_real;
	double		c_imag;
	double		zoom;
	double		offset_x;
	double		offset_y;
	mlx_image_t	*pic;
	mlx_t		*mlx;
	int			color;
	int			width;
	int			height;
	int			max;
	char		*name;
}				t_fractal;

// Mandelbrot
int				ft_mandelbrot(t_fractal *fractal);
void			*ft_draw_mandelbrot(void *void_pointer);

// Main
void			ft_exit_fractal(t_fractal *fractal);
void			ft_which_fractal(t_fractal *fractal, char *type);
void			ft_init_fractal(t_fractal *fractal);
void			ft_init_julia(t_fractal *fractal, char *param1, char *param2);

// MLX window
void			ft_keys(mlx_key_data_t keys, void *param);
void			ft_init_win(t_fractal *fractal, char *type, char *p1, char *p2);
void			ft_mlx_error(void);
void			ft_mouse(mouse_key_t mouse, action_t action, modifier_key_t mod,
					void *param);
void			ft_resize_win(int32_t width, int32_t height, void *param);

// Draw fractals
void			ft_change_max(t_fractal *fractal, int key_code);
void			ft_zoom(t_fractal *fractal, int x, int y, int zoom);
void			ft_color_pixel(t_fractal *fractal, int x, int y, int color);
void			ft_scroll(double up, double down, void *param);

// Julia
double			ft_make_random(void);
void			ft_random_julia(double *c_real, double *c_imag);
void			ft_draw_julia(t_fractal *fractal);
void			ft_julia(t_fractal *fractal);

// Burning ship
int				ft_burningship(t_fractal *fractal);
void			ft_draw_burningship(t_fractal *fractal);

#endif

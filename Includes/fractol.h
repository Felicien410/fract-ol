#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<unistd.h>
#include <mlx.h>

// typedef struct	s_data {
// 	void	*img;
// 	int	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// 	void	*mlx;
// 	void	*win;
// }				t_vars;

typedef struct cor
{
	double	corx;
	double	cory;
}	t_cor;

typedef struct s_data
{
	int		i;
	void	*mlx;
	void	*win;
	int		*addr;
	int		x;
	int		y;
	int		width;
	int		height;
	void	*img;
	int		bits_per_pixel;
	int		endian;
	int		line_length;
	double	cr;
	double	ci;
	double	maxr;
	double	maxi;
	double	minr;
	double	mini;
	int		itter;
	int		id;
	t_cor	zoom;
}	t_vars;

void	my_mlx_pixel_put(t_vars *data, int x, int y, int color);
void	ft_putstr_fd(char *s, int fd);
int	key_press(int keycode, t_vars *vars);
void put_squarre (t_vars *img);
int	mouse(int keycode, t_vars *vars);
void	clear_redraw(t_vars *vars);

void	ft_julia(t_vars *data);
void	draw_julia(t_vars *fractol);
int	itter(double cr, double ci, double max, t_vars *fra);

#endif
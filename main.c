#include"Includes/fractol.h"

int	main(void)
{
	t_data	img;
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	printf("%s-->",img.addr);
	put_squarre (&img);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win,2, 0, key_press, &vars);
	mlx_mouse_hook(vars.win,mouse, &vars);
	mlx_loop(vars.mlx);
}

// typedef struct	s_fractol
// {
// 	void		*mlx;
// 	void		*win;
// 	void		*img;
// 	void		*img_ptr;
// 	int			endian;
// 	int			sl;
// 	int			bpp;
// 	int			fract;
// 	int			color;
// 	int			julia_mouse;
// 	int			x;
// 	int			y;
// 	int			y_max;
// 	int			it;
// 	int			it_max;
// 	int			show_text;
// 	double		zoom;
// 	double		x1;
// 	double		y1;
// 	double		c_r;
// 	double		c_i;
// 	double		z_r;
// 	double		z_i;
// 	double		tmp;
// }				t_fractol;

// void	ft_zoom(int x, int y, t_fractol *data)
// {
// 	data->x1 = (x / data->zoom + data->x1) - (x / (data->zoom * 1.3));
// 	data->y1 = (y / data->zoom + data->y1) - (y / (data->zoom * 1.3));
// 	data->zoom *= 1.3;
// 	data->it_max++;
// }

// void	ft_dezoom(int x, int y, t_fractol *data)
// {
// 	data->x1 = (x / data->zoom + data->x1)  - (x / (data->zoom / 1.3));
// 	data->y1 = (y / data->zoom + data->y1) - (y / (data->zoom / 1.3));
// 	data->zoom /= 1.3;
// 	data->it_max--;
// }

// int		mouse_hook(int mousecode, int x, int y, t_fractol *data)
// {
// 	if (mousecode == 4 || mousecode == 1)
// 		ft_zoom(x, y, data);
// 	else if (mousecode == 5 || mousecode == 2)
// 		ft_dezoom(x, y, data);
// 	fract_calc(data);
// 	return (0);
// }
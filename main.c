#include"Includes/fractol.h"

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "Hello world!");
	vars.img = mlx_new_image(vars.mlx, 500, 500);
	vars.addr = (int *)
		mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length,
								&vars.endian);
	printf("->%d\n",vars.bits_per_pixel);
	printf("->%d\n",vars.line_length);
	printf("->%d\n",vars.endian);
	// vars.addr[480 + 2] = 0x00FF0000 * 3;
	// vars.addr[3400] = 0x00FF0000 ;


	// put_squarre (&vars);
	ft_julia(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
	mlx_hook(vars.win,2, 0, key_press, &vars);
	mlx_hook(vars.win, 4, 0, &mouse, &vars);
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
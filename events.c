#include"Includes/fractol.h"
#include"Includes/buttons.h"

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	mouse(int keycode, t_vars *vars)
{
	if (keycode == MOUSE_UP)
    {
        printf("zoom avant");
		ft_putstr_fd(" z a", 2);
		clear_redraw(vars);
    }
    if (keycode == MOUSE_DOWN)
    {
        printf("zoom arriere");
    }
	// mlx_destroy_window(vars->mlx, vars->win);
	// exit(0);

	return (0);
}

int	zoom(int keycode, int x, int y, t_vars *fractol)
{
	double	im_range;
	double	re_range;

	re_range = fractol->minr
		+ ((double)x * (fractol->maxr - fractol->minr)) / WIDTH;
	im_range = fractol->mini
		+ ((double)y * (fractol->maxi - fractol->mini)) / HEIGHT;
	if (keycode == MOUSE_UP)
	{
		fractol->itter += 2;
		fractol->minr = re_range + (fractol->minr - re_range) * 0.9;
		fractol->mini = im_range + (fractol->mini - im_range) * 0.9;
		fractol->maxr = re_range + (fractol->maxr - re_range) * 0.9;
		fractol->maxi = im_range + (fractol->maxi - im_range) * 0.9;
	}
	if (keycode == MOUSE_DOWN)
	{
		fractol->minr = re_range + (fractol->minr - re_range) * 1.1;
		fractol->mini = im_range + (fractol->mini - im_range) * 1.1;
		fractol->maxr = re_range + (fractol->maxr - re_range) * 1.1;
		fractol->maxi = im_range + (fractol->maxi - im_range) * 1.1;
		fractol->itter -= 2;
	}
	clear_redraw(fractol);
	return (0);
}

void	clear_redraw(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img);
	ft_putstr_fd("destroy fait", 2);
	vars->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	mlx_clear_window(vars->mlx, vars->win);
	draw_julia (vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	ft_putstr_fd("nouvelle image", 2);

}

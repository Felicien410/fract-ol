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

void	clear_redraw(t_vars *vars)
{
	ft_putstr_fd("dddd", 2);
	mlx_destroy_image(vars->mlx, vars->img);
	ft_putstr_fd("dddd", 2);
	vars->img = mlx_new_image(vars->mlx, 500, 500);
	mlx_clear_window(vars->mlx, vars->win);
	// put_squarre (vars);
	// // if (vars->id == 2)
	// // 	draw_julia(vars);
	// // else if (vars->id == 1)
	// // 	draw_mand(vars);
	// // else if (vars->id == 3)
	// // 	draw_burn(vars);
	//mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}

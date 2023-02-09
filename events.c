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
    }
    if (keycode == MOUSE_DOWN)
    {
        printf("zoom arriere");
    }
	// mlx_destroy_window(vars->mlx, vars->win);
	// exit(0);

	return (0);
}


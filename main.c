#include"Includes/fractol.h"
#include"Includes/buttons.h"

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "FRACTALL PTNNN");
	vars.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	vars.addr = (int *)
		mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length,
								&vars.endian);
	// vars.addr[480 + 2] = 0x00FF0000 * 3;
	// vars.addr[3400] = 0x00FF0000 ;
	ft_julia(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
	mlx_hook(vars.win,2, 0, key_press, &vars);
	mlx_hook(vars.win, 4, 0, &zoom, &vars);
	mlx_loop(vars.mlx);
}
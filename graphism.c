#include"Includes/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void put_squarre (t_data *img)
{
    int x = 0;
    int y = 0;

    while (x < 50)
    {
        while (y < 50)
        {
            my_mlx_pixel_put(img, y, x, 0x000000FF);
            y++;
        }
        y = 0;
        x ++;
}
}
#include"Includes/fractol.h"
#include"Includes/buttons.h"



void put_squarre (t_vars *img)
{
    int x = 30;
    int y = 30;

    while (x < WIDTH - 20)
    {
        while (y < HEIGHT - 20)
        {
            	img->addr[y * WIDTH + x] = 0x00FF0000;
            y++;
        }
        y = 20;
        x ++;
}
}

int calc (int i)
{
    int y = 0;
    while (i < 250 && y < 250)
    {
        i = i * i - 1;
        y++;
        printf ("%d\n", i);
    }
    return i;
}

void put_fract (t_vars *fractol)
{
	// int		x;
	// int		y;
	// int		i;

	// x = 0;
	// i = 0;
    // int z = 0;
	// while (x < WIDTH)
	// {
        
	// 	y = 0;
    //     i= 0;
	// 	while (y < HEIGHT)
	// 	{
    //         i = calc(i);
    //         if ( i == 250)
    //         {
	// 			fractol->addr[(y * WIDTH) + x] = 0x00000000;
    //         }
	// 		else
	// 			fractol->addr[(y * HEIGHT + x)] = 0x00FF0000 * i;
    //         z ++;
	// 		y++;
    //         i = z;
	// 	}
	// 	x++;
	// }
    calc (0);
}

int	itter(double x, double y, double max, t_vars *fra)
{
	double	tmp;
	int		i;
    int pala;

	i = 0;
    pala = 0;
	while (i <= max && (x * x + y * y) <= 4)
	{
		tmp = x;
		x = x * x - y * y - 1  ;//- fra->zoom.corx;
		y = 2 * y * tmp ;// fra->zoom.cory;
		i++;
	}
    
    // if (i != pala)
    //     printf("%d\n", i);
    //     pala = i;
        
// ptn jveux un truc qui affiche qu 1 i a la fois
	return (i);
}

void	draw_julia(t_vars *fractol)
{
	int		x;
	int		y;
	int		i;

	x = 0;
	i = 0;
    put_fract (fractol);
	while (x < WIDTH)
	{
		fractol->cr = fractol->minr + (fractol->maxr - fractol->minr) * x / WIDTH;
        
		y = 0;
		while (y < HEIGHT)
		{
			fractol->ci = fractol->mini + (fractol->maxi - fractol->mini)
				* y / WIDTH;
            
			i = itter(fractol->cr, fractol->ci, fractol->itter, fractol);
			if (i == 0)
            {
				fractol->addr[(y * WIDTH) + x] = 0x000000;
            }
			else
				fractol->addr[(y * HEIGHT + x)] = 0xE6E6FA * i;
			y++;
		}
		x++;
	}
}
void	ft_julia(t_vars *data)
{
	data->zoom.corx = 0.8;
	data->zoom.cory = 0.1;
	data->minr = -2;
	data->mini = -2;
	data->maxr = 2;
	data->maxi = 2;
	data->itter = 250;
	draw_julia(data);
}

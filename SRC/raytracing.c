/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:45:52 by mcreus            #+#    #+#             */
/*   Updated: 2023/09/22 11:10:11 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


/*void	init_screen(t_data *data)
{
	if (data == NULL)
	{
		free(data);
		exit(1);
	}
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, width, height, "new project");
	draw_2d(data->mlx, data->win);
	//draw_player(data);
	mlx_loop(data->mlx);
}
*/
/*void	draw_player(t_data *data)
{
	data->p_x = 300;
	data->p_y = 300;
	
	int	square_size = 10;
	int color = 0x00FF00; 
	draw_square(data->mlx, data->win, data->p_x, data->p_y, square_size, color);
}


void draw_square(void *mlx, void *win, int x, int y, int size, int color)
{
	(void) x;
	(void) y;
	(void) mlx;
	(void) win;
	(void) size;
	(void) color;
	
    int half_size = size / 2;

	int	i = x - half_size;
	while (i < x + half_size)
	{
		int	j = y - half_size;
		while (j < y + half_size)
		{
            mlx_pixel_put(mlx, win, i, j, color);
			j++;
		}
		i++;
	}
}

void draw_square2(void *mlx_ptr, void *win_ptr, int x, int y, int color)
{
    int i, j;
	
	i = 0;
    while (i < )
    {
		j = 0;
        while (j < mapS)
        {
            mlx_pixel_put(mlx_ptr, win_ptr, x + i, y + j, color);
			j++;
        }
		i++;
    }
}*/

void	draw_2d(void *mlx, void *win)
{
    int     color;
	int		x;
	int		y;
	int		mapX;
	int 	mapY;
	int		i;
	int		j;
    t_data  *data;

	mapX = 10;
	mapY = 10;
    y = 0;
    while (y < mapY)
    {
        x = 0;
        while (x < mapX)
        {
            if (data->map2[y * mapX +x] > 0)
				color = 0xFFFFFF;
			else
				color = 0x000000;
			data->p_xo = x * casePixel;
			data->p_yo = y * casePixel;
			i = data->p_xo;
			while (i < data->p_xo + casePixel)
			{
				j = data->p_yo;
				while (j < data->p_yo + casePixel)
				{
					mlx_pixel_put(mlx, win, i, j, color);
					j++;
				}
				i++;
			}
			x++;
        }
		y++;
    }
}

void	fill_map_to_data()
{
	int		x;
	int		y;
	int		mapX;
	int		mapY;
	char 	cell;
	t_data	*data;

	mapX = 10;
	mapY = 10;
	y = 0;
	while (y < mapY)
	{
		x = 0;
		while (x < mapX)
		{
			cell = &data->map[x][y];
			if (cell == '1')
				data->map2[y * mapX + x] = 1;
			else
				data->map2[y * mapX + x] = 0;
			x++;
		}
		y++;
	}
}

/*void	draw_3d()
{
	int	r;
	int	mx;
	int	my;
	int	mp;
	int	dof;

	float	rx;
	float	ry;
	float	ra;
	float	xo;
	float	yo;
	float	PI = 3.14;

	ra = pa;
	r = 0;
	while (r < 1)
	{
		dof = 0;
		float	aTan = -1/tan(ra);
		if (ra > P2 && ra < P3)
		{
			ry = (((int) py >> 6) << 6) - 0.0001;
			rx = (py - ry) * aTan + px;
			yo = -64;
			xo = -yo * aTan;
		}
		if (ra < P2 && ra > P3)
		{
			ry = (((int) py >> 6) << 6) + 64;
			rx = (py - ry) * aTan + px;
			yo = -64;
			xo = -yo * aTan;
		}
		if (ra == 0 || ra == PI)
		{
			rx = px;
			ry = py;
			dof = 8;
		}
		
		while (dof < 8)
		{
			mx = (int) (rx) >> 6;
			my = (int) (ry) >> 6;
			mp = my * mapX + mx;
			if (mp < mapX * mapY && map[mp] == 1)
				dof = 8;
			else
			{
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}
	}
}*/
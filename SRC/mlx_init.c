/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:45:12 by mcreus            #+#    #+#             */
/*   Updated: 2023/09/20 17:59:21 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>


/*void	ft_put_window(t_data *data, int i, int j);
{
	while (i < data->lines)
	{
		j = 0;
		while (data->map[i][j] != '\n' && data->map[i][j] != '\0')
		{
			if (data->map[i][j] == '1')
				mlx_put_image_to_window
		}
	}
}*/

/*void	img_init(t_data *data, char *av)
{
	data->north = mlx_xpm_file_to_image(data->mlx, data->no_p,
		&data->x, &data->y);
	data->south = mlx_xpm_file_to_image(data->mlx, data->so_p,
		&data->x, &data->y);
	data->east = mlx_xpm_file_to_image(data->mlx, data->ea_p,
		&data->x, &data->y);
	data->west = mlx_xpm_file_to_image(data->mlx, data->we_p,
		&data->x, &data->y);
}*/


/*void	ft_put_image(t_data *data, int y, int x, char flag)
{
	if (flag == 'A')
		mlx_put_image_to_window(data->mlx, data->win, data->no,
			x * SIZE, y * SIZE);
	else if (flag == 'W')
		mlx_put_image_to_window(data->mlx, data->win, data->playerw_img,
			x * SIZE, y * SIZE);
	else if (flag == 'S')
		mlx_put_image_to_window(data->mlx, data->win, data->players_img,
			x * SIZE, y * SIZE);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->playerd_img,
			x * SIZE, y * SIZE);
}*/

void	init_screen(t_data *data)
{
	if (data == NULL)
	{
		free(data);
		exit(1);
	}
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 600, 600, "new project");
	draw_2d(data->mlx, data->win);
	draw_player(data);
	mlx_loop(data->mlx);
}

void	draw_player(t_data *data)
{
	data->p_x = 300;
	data->p_y = 300;
	
	int	square_size = 10;
	int color = 0x00FF00; /*vert*/
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
    while (i < mapS)
    {
		j = 0;
        while (j < mapS)
        {
            mlx_pixel_put(mlx_ptr, win_ptr, x + i, y + j, color);
			j++;
        }
		i++;
    }
}

void	draw_2d(void *mlx, void *win)
{
	int	x;
	int	y;
	int	map[mapX][mapY] = 
	{
	1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,
	};
	
	y = 0;
	while (y < mapY)
	{
		x = 0;
		while (x < mapX)
		{
			if (map[x][y] == 1)
			{
				draw_square2(mlx, win, x * mapS, y * mapS, 0xFFFFFF);
			}
			else
			{
				draw_square2(mlx, win, x * mapS, y * mapS, 0x000000);
			}
			/*mlx_pixel_put(mlx, win, xo, yo, );
			mlx_pixel_put(xo, yo + mapS);
			mlx_pixel_put(xo + mapS, yo + mapS);*/
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
}*/
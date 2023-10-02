/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_alex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:45:41 by aperrein          #+#    #+#             */
/*   Updated: 2023/10/02 15:00:02 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	background(t_data *data)
{
	int		i;
	int		j;
	int		ceil;
	int		floo;

	i = 0;
	ceil = (data->ceiling.r << 16 | data->ceiling.g << 8 | data->ceiling.b);
	floo = (data->floor.r << 16 | data->floor.g << 8 | data->floor.b);
	while (i < (HEIGHT / 2))
	{
		j = 0;
		while (j < WIDTH)
		{
			img_pix_put(&data->img_f, j++, i, ceil);
		}
		++i;
	}
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			img_pix_put(&data->img_f, j++, i, floo);
		}
		++i;
	}
}

void	test_ray(t_data *data)
{
	int		x;
	int		color;

	x = 0;
	while (x < WIDTH)
	{
		data->ray.camerax = 2 * x / (double)WIDTH - 1;
		data->ray.ray_dirx = data->dir_x + data->plan_x * data->ray.camerax;
		data->ray.ray_diry = data->dir_y + data->plan_y * data->ray.camerax;
		data->ray.mapx = (int)data->x;
		data->ray.mapy = (int)data->y;
		data->ray.delta_distx = fabs(1 / data->ray.ray_dirx);
		data->ray.delta_disty = fabs(1 / data->ray.ray_diry);
		data->ray.hit = 0;
		if (data->ray.ray_dirx < 0)
		{
			data->ray.stepx = -1;
			data->ray.side_distx = (data->x - data->ray.mapx)
				* data->ray.delta_distx;
		}
		else
		{
			data->ray.stepx = 1;
			data->ray.side_distx = (data->ray.mapx + 1.0 - data->x)
				* data->ray.delta_distx;
		}
		if (data->ray.ray_diry < 0)
		{
			data->ray.stepy = -1;
			data->ray.side_disty = (data->y - data->ray.mapy)
				* data->ray.delta_disty;
		}
		else
		{
			data->ray.stepy = 1;
			data->ray.side_disty = (data->ray.mapy + 1.0 - data->y)
				* data->ray.delta_disty;
		}
		while (data->ray.hit == 0)
		{
			if (data->ray.side_distx < data->ray.side_disty)
			{
				data->ray.side_distx += data->ray.delta_distx;
				data->ray.mapx += data->ray.stepx;
				data->ray.side = 0;
			}
			else
			{
				data->ray.side_disty += data->ray.delta_disty;
				data->ray.mapy += data->ray.stepy;
				data->ray.side = 1;
			}
			if (data->map[data->ray.mapy][data->ray.mapx] == '1')
				data->ray.hit = 1;
		}
		if (data->ray.side == 0)
		{
			data->ray.perp_wall_dist = (data->ray.side_distx
					- data->ray.delta_distx);
		}
		else
		{
			data->ray.perp_wall_dist = (data->ray.side_disty
					- data->ray.delta_disty);
		}
		if (data->ray.perp_wall_dist)
			data->ray.line_height = (int)(HEIGHT / data->ray.perp_wall_dist);
		else
			data->ray.line_height = (int)(HEIGHT / 0.5);
		data->ray.draw_start = -data->ray.line_height / 2 + HEIGHT / 2;
		if (data->ray.draw_start < 0)
			data->ray.draw_start = 0;
		data->ray.draw_end = data->ray.line_height / 2 + HEIGHT / 2;
		if (data->ray.draw_end >= HEIGHT)
			data->ray.draw_end = HEIGHT - 1;
		if (data->ray.side == 1 && data->ray.mapy >= data->y)
			color = 16711680;		//red east
		else if (data->ray.side == 1 && data->ray.mapy < data->y)
			color = 65280;			//green west
		if (data->ray.side == 0 && data->ray.mapx >= data->x)
			color = 255;		//blue north
		else if (data->ray.side == 0 && data->ray.mapx < data->x)
			color = 16776960;			//yellow south
		while (data->ray.draw_start < data->ray.draw_end)
			img_pix_put(&data->img_f, x, data->ray.draw_start++, color);
		x++;
	}
}

int	view(t_data *data)
{
	if (!data->win)
		return (1);
	background(data);
	test_ray(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img_f.mlx_img, 0, 0);
	ft_moves_ws(data);
	ft_moves_ad(data);
	ft_rotate1(data);
	return (0);
}

void	game_init(t_data *data)
{
	data->mlx = mlx_init();
	init_ray(data);
	if (!data->mlx)
		return ;
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3d");
	if (!data->win)
		return ;
	data->img_f.mlx_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img_f.addr = mlx_get_data_addr(data->img_f.mlx_img, &data->img_f.bpp,
			&data->img_f.line_len, &data->img_f.endian);
	mlx_loop_hook(data->mlx, &view, data);
	mlx_hook(data->win, DestroyNotify, ButtonPressMask, &ft_finish, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, &handle_input, data);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask,
		&handle_input_release, data);
	mlx_loop(data->mlx);
	mlx_destroy_image(data->mlx, data->img_f.mlx_img);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}
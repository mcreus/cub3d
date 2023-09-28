/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:45:12 by mcreus            #+#    #+#             */
/*   Updated: 2023/09/28 19:00:15 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*void	img_init(t_data *data, char *av)
{
	(void)av;
	data->north = mlx_xpm_file_to_image(data->mlx, data->no_p,
		&data->x, &data->y);
	data->south = mlx_xpm_file_to_image(data->mlx, data->so_p,
		&data->x, &data->y);
	data->east = mlx_xpm_file_to_image(data->mlx, data->ea_p,
		&data->x, &data->y);
	data->west = mlx_xpm_file_to_image(data->mlx, data->we_p,
		&data->x, &data->y);
}*/
void	ft_moves_ws(t_data *data)
{
	if (data->moves.move_forward == 1)
	{
		if (data->map[(int)(data->y + (data->dir_y
					* data->moves.move_speed * 2))][(int)data->x] == '0')
			data->y += data->dir_y * data->moves.move_speed;
		if (data->map[(int)(data->y)][(int)(data->x +
					(data->dir_x * data->moves.move_speed * 2))] == '0')
			data->x += data->dir_x * data->moves.move_speed;
	}
	if (data->moves.move_back == 1)
	{
		if (data->map[(int)(data->y - (data->dir_y
					* data->moves.move_speed * 2))][(int)(data->x)] == '0')
			data->y -= data->dir_y * data->moves.move_speed;
		if (data->map[(int)(data->y)][(int)(data->x -
					(data->dir_x * data->moves.move_speed * 2))] == '0')
			data->x -= data->dir_x * data->moves.move_speed;
	}
}

void	ft_moves_ad(t_data *data)
{
	if (data->moves.step_to_right == 1)
	{
		if (data->map[(int)(data->y + data->dir_x
				* (data->moves.move_speed * 2))][(int)data->x] == '0')
			data->y += data->dir_x * data->moves.move_speed;
		if (data->map[(int)data->y][(int)(data->x
			- data->dir_y * (data->moves.move_speed * 2))] == '0')
			data->x -= data->dir_y * data->moves.move_speed;
	}
	if (data->moves.step_to_left == 1)
	{
		if (data->map[(int)(data->y - data->dir_x
				* (data->moves.move_speed * 2))][(int)data->x] == '0')
			data->y -= data->dir_x * data->moves.move_speed;
		if (data->map[(int)data->y][(int)(data->x
			+ data->dir_y * (data->moves.move_speed * 2))] == '0')
			data->x += data->dir_y * data->moves.move_speed;
	}
}

void	ft_rotate1(t_data *data)
{
	float	old_planx;
	float	old_dirx;

	old_planx = data->plan_x;
	old_dirx = data->dir_x;
	if (data->moves.rotate_left == 1)
	{
		data->dir_x = data->dir_x * cos(-data->moves.rotate_speed / 2)
			- data->dir_y * sin(-data->moves.rotate_speed / 2);
		data->dir_y = old_dirx * sin(-data->moves.rotate_speed / 2)
			+ data->dir_y * cos(-data->moves.rotate_speed / 2);
		data->plan_x = data->plan_x * cos(-data->moves.rotate_speed / 2)
			- data->plan_y * sin(-data->moves.rotate_speed / 2);
		data->plan_y = old_planx * sin(-data->moves.rotate_speed / 2)
			+ data->plan_y * cos(-data->moves.rotate_speed / 2);
	}
	else
		ft_rotate2(data);
}

void	ft_rotate2(t_data *data)
{
	float	old_planx;
	float	old_dirx;

	old_planx = data->plan_x;
	old_dirx = data->dir_x;
	if (data->moves.rotate_right == 1)
	{
		data->dir_x = data->dir_x * cos(data->moves.rotate_speed / 2)
			- data->dir_y * sin(data->moves.rotate_speed / 2);
		data->dir_y = old_dirx * sin(data->moves.rotate_speed / 2)
			+ data->dir_y * cos(data->moves.rotate_speed / 2);
		data->plan_x = data->plan_x * cos(data->moves.rotate_speed / 2)
			- data->plan_y * sin(data->moves.rotate_speed / 2);
		data->plan_y = old_planx * sin(data->moves.rotate_speed / 2)
			+ data->plan_y * cos(data->moves.rotate_speed / 2);
	}
}

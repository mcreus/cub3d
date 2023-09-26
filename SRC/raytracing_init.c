/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 22:37:37 by mcreus            #+#    #+#             */
/*   Updated: 2023/09/25 23:21:15 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray(t_data *data)
{
	data->start_player = 'p';
	data->moves.move_forward = 0;
	data->moves.move_back = 0;
	data->moves.step_to_left = 0;
	data->moves.step_to_right = 0;
	data->moves.rotate_right = 0;
	data->moves.rotate_left = 0;
	data->pos_x = (float)data->x + 0.5;
	data->pos_y = (float)data->y + 0.5;
	data->dir_x = 0;
	data->dir_y = 0;
	data->plan_x = 0;
	data->plan_y = 0;
	data->moves.move_speed = 0.1;
	data->moves.rotate_speed = 0.033 * 1.8;
	init_dir(data);
}

void	init_dir(t_data *data)
{
	if (data->start_player == 'N')
		data->dir_x = -1;
	if (data->start_player == 'S')
		data->dir_x = 1;
	if (data->start_player == 'E')
		data->dir_y = 1;
	if (data->start_player == 'W')
		data->dir_y = -1;
	if (data->start_player == 'N')
		data->plan_y = 0.66;
	if (data->start_player == 'S')
		data->plan_y = -0.66;
	if (data->start_player == 'E')
		data->plan_x = 0.66;
	if (data->start_player == 'W')
		data->plan_x = -0.66;
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:52:39 by mcreus            #+#    #+#             */
/*   Updated: 2023/09/25 15:16:12 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
void	check_player(t_data *data)
{
	if (data->N != 1 || data->S != 1 || data->W != 1 || data->E !=1)
	{
		ft_putstr_fd("Error\n Wrong number of views\n", 2);
		ft_finish(data);
		exit(0);
	}
}

void	check_lines(t_data *data)
{
	data->lines = ft_count_lines(data);
	if (data->lines < 3)
	{
		ft_putstr_fd("Error\nYou will need more lines in your map!\n", 2);
		ft_finish(data);
		exit (0);
	}
}

void	check_columns(t_data *data)
{
	data->columns = data->map[0];
	if (data->columns < 3)
	{
		ft_putstr_fd("Error\nYou will need more columns in your map!\n", 2);
		ft_finish(data);
		exit (0);
	}
	check_lines(data);
}

void	check_walls(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->columns)
	{
		if (data->map[0][i] != '1' || data->map[data->lines - 1][i] != '1')
		{
			ft_putstr_fd("Error\nWall not valid!\n", 2);
			ft_finish(data);
		}
		i++;
	}
	i = 1;
	while (i < data->lines - 1)
	{
		if (data->map[i][0] != '1' || data->map[i][data->columns - 1] != '1')
		{
			ft_putstr_fd("Error\nWall not valid!\n", 2);
			ft_finish2(data);
		}
		i++;
	}
	check_columns(data);	
}

int	flood_fill(t_data *data, int x, int y, char **map)
{
	if (y < 0 || x < 0 || y > data->lines || x > data->columns
		|| map[y][x] == '1' || map[y][x] == 'X')
		return (0);
	if (map[y][x] != '0')
		return (0);
	map[y][x] = 'X';
	flood_fill(data, map, x + 1, y);
	flood_fill(data, map, x - 1, y);
	flood_fill(data, map, x, y + 1);
	flood_fill(data, map, x, y - 1);
	return (1);
}

void	ft_check_path(t_data *data)
{
	ft_map_dup(data);
	if (ft_flood_fill(data, data->map_dup, data->p_x, data->p_y) != 1)
	{
		ft_putstr_fd("Error\nInvalid Map Path\n", 2);
		ft_free_map2(data);
		ft_finish2(data);
	}
	else
		ft_free_map2(data);
}
*/
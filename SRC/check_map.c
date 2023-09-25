/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:52:39 by mcreus            #+#    #+#             */
/*   Updated: 2023/09/22 18:28:47 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	if (data->lines < 3)
	{
		ft_putstr_fd("Error\nYou will need more lines in your map!\n", 2);
		ft_finish2(data);
		exit (0);
	}
}

void	check_columns(t_data *data)
{
	data->columns = data->map[0];
	if (data->columns < 3)
	{
		ft_putstr_fd("Error\nYou will need more columns in your map!\n", 2);
		ft_finish2(data);
		exit (0);
	}
}
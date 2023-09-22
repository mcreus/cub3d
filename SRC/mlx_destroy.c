/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:41:15 by mcreus            #+#    #+#             */
/*   Updated: 2023/09/22 16:11:44 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}

int	ft_finish(t_data *data)
{
	mlx_destroy_image(data->mlx, data->ea_p);
	mlx_destroy_image(data->mlx, data->so_p);
	mlx_destroy_image(data->mlx, data->we_p);
	mlx_destroy_image(data->mlx, data->no_p);
	ft_free_map(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}
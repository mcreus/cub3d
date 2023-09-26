/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:41:15 by mcreus            #+#    #+#             */
/*   Updated: 2023/09/25 15:18:24 by mcreus           ###   ########.fr       */
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

void	ft_free_map2(t_data *data)
{
	int	i;

	i = 0;
	while (data->map_dup[i])
	{
		free(data->map_dup[i]);
		i++;
	}
	free(data->map_dup);
}

int	ft_finish(t_data *data)
{
	mlx_destroy_image(data->mlx, data->ea_p);
	mlx_destroy_image(data->mlx, data->so_p);
	mlx_destroy_image(data->mlx, data->we_p);
	mlx_destroy_image(data->mlx, data->no_p);
	mlx_destroy_display(data->mlx);
	if (data->map != 0)
		ft_free_map(data);
	
	free(data->mlx);
	exit(0);
}
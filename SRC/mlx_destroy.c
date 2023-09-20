/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:41:15 by mcreus            #+#    #+#             */
/*   Updated: 2023/09/20 10:11:35 by mcreus           ###   ########.fr       */
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

int	mlx_destroy(t_data *data)
{
	mlx_destroy_image(data->mlx, data->east);
	mlx_destroy_image(data->mlx, data->north);
	mlx_destroy_image(data->mlx, data->east);
	mlx_destroy_image(data->mlx, data->west);
	free_error(data, "Fin du game!\n");
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}
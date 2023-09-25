/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:45:12 by mcreus            #+#    #+#             */
/*   Updated: 2023/09/25 13:35:50 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>


void	img_init(t_data *data, char *av)
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
}

int	handle_input(int keysym, t_data *data)
{
	int result;

	result = 0;
	if (keysym == 65307)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	if (keysym == 119)
		result = ft_move_player(data, data->p_y - 1, data->p_x, 'W');
	if (keysym == 97)
		result = ft_move_player(data, data->p_y, data->p_x - 1, 'A');
	if (keysym == 115)
		result = ft_move_player(data, data->p_y + 1, data->p_x, 'S');
	if (keysym == 100)
		result = ft_move_player(data, data->p_y, data->p_x + 1, 'D');
	return (0);
}

int	ft_move_player(t_data *data, int y, int x, char flag)
{
	if (data->map[y][x] == '0')
	{
		mlx_put_image_to_window(data->mlx, data->win, /*          */, data->p_x * TEXTURE, data->p_y * TEXTURE);
		data->map[data->p_y][data->p_x] = '0';
		data->map[y][x] = '0';
		data->p_y = y;
		data->p_x = x;
		return (1);
	}
}
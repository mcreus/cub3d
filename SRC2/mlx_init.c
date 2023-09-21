/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:45:12 by mcreus            #+#    #+#             */
/*   Updated: 2023/09/19 17:36:30 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_map_index(t_data *data)
{
	int		i;
	char	*str;

	i = 0;
	while (i <= data->lines)
	{
		str = get_next_line(data->fd);
		if (!str)
		{
			free(str);
			break ;
		}
		data->map[i] = ft_strtrim(str, "\n");
		free(str);
		i++;
	}
	data->columns = ft_strlen(data->map[0]);
	
}

/*void	ft_put_window(t_data *data, int i, int j);
{
	while (i < data->lines)
	{
		j = 0;
		while (data->map[i][j] != '\n' && data->map[i][j] != '\0')
		{
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->)
		}
	}
}*/

void	img_init(t_data *data, char *av)
{
	data->north = mlx_xpm_file_to_image(data->mlx, data->no_p,
		&data->x, &data->y);
	data->south = mlx_xpm_file_to_image(data->mlx, data->so_p,
		&data->x, &data->y);
	data->east = mlx_xpm_file_to_image(data->mlx, data->ea_p,
		&data->x, &data->y);
	data->west = mlx_xpm_file_to_image(data->mlx, data->we_p,
		&data->x, &data->y);
	read_map(data, av);
}

void	read_map(t_data *data, char *av)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	data->fd = open(av, O_RDONLY);
	data->lines = count_lines(data);
	close (data->fd);
	data->fd = open(av, O_RDONLY);
	data->map = ft_calloc(data->lines + 1, sizeof (char *));
	ft_map_index(data);
	data->win = mlx_new_window(data->mlx, ft_strlen(data->map[0]) * width,
		data->lines * height, "cub3d");
	if (data->win == NULL)
	{
		free(data->win);
		return ;
	}
	//ft_put_window(data, i, j);
	close (data->fd);
}
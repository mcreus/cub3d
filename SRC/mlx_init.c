/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:45:12 by mcreus            #+#    #+#             */
/*   Updated: 2023/09/20 12:56:25 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>


/*void	ft_put_window(t_data *data, int i, int j);
{
	while (i < data->lines)
	{
		j = 0;
		while (data->map[i][j] != '\n' && data->map[i][j] != '\0')
		{
			if (data->map[i][j] == '1')
				mlx_put_image_to_window
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
}

/*void	draw_3d()
{
	int	r;
	int	mx;
	int	my;
	int	mp;
	int	dof;

	float	rx;
	float	ry;
	float	ra;
	float	xo;
	float	yo;
	float	PI = 3.14;

	ra = pa;
	r = 0;
	while (r < 1)
	{
		dof = 0;
		float	aTan = -1/tan(ra);
		if (ra > PI)
		{
			ry = (((int) py >> 6) << 6) - 0.0001;
			rx = (py - ry) * aTan + px;
			yo = -64;
			xo = -yo * aTan;
		}
		if (ra < PI)
		{
			ry = (((int) py >> 6) << 6) + 64;
			rx = (py - ry) * aTan + px;
			yo = -64;
			xo = -yo * aTan;
		}
	}
	while (dof < 8)
	{
		mx = (int) (rx) >> 6;
		my = (int) (ry) >> 6;
		mp = my * mapX + mx;
	}
}*/
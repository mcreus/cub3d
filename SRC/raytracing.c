/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:45:52 by mcreus            #+#    #+#             */
/*   Updated: 2023/09/22 15:34:08 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


/*void	start_ray(t_data *data)
{
	float	time;
	float	old_time;
	int		width;
	
	data->p_x = 22;
	data->p_y = 12;
	data->dir_x = -1;
	data->dir_y = 0;
	time = 0;
	old_time = 0;
	while (!done())
	{
		
	}
}

void	draw_3d()
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
		if (ra > P2 && ra < P3)
		{
			ry = (((int) py >> 6) << 6) - 0.0001;
			rx = (py - ry) * aTan + px;
			yo = -64;
			xo = -yo * aTan;
		}
		if (ra < P2 && ra > P3)
		{
			ry = (((int) py >> 6) << 6) + 64;
			rx = (py - ry) * aTan + px;
			yo = -64;
			xo = -yo * aTan;
		}
		if (ra == 0 || ra == PI)
		{
			rx = px;
			ry = py;
			dof = 8;
		}
		
		while (dof < 8)
		{
			mx = (int) (rx) >> 6;
			my = (int) (ry) >> 6;
			mp = my * mapX + mx;
			if (mp < mapX * mapY && map[mp] == 1)
				dof = 8;
			else
			{
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}
	}
}*/
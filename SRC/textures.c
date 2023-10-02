/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:44:38 by mcreus            #+#    #+#             */
/*   Updated: 2023/10/02 14:37:08 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    text_addr(t_data *data)
{
    data->img_f.addr = mlx_get_data_addr(data->img_f.north, &data->img_f.bpp,
            &data->img_f.line_len, &data->img_f.endian);
    data->img_f.addr = mlx_get_data_addr(data->img_f.south, &data->img_f.bpp,
            &data->img_f.line_len, &data->img_f.endian);
    data->img_f.addr = mlx_get_data_addr(data->img_f.east, &data->img_f.bpp,
            &data->img_f.line_len, &data->img_f.endian);
    data->img_f.addr = mlx_get_data_addr(data->img_f.west, &data->img_f.bpp,
            &data->img_f.line_len, &data->img_f.endian);
}

void	img_init(t_data *data)
{
	data->img_f.north = mlx_xpm_file_to_image(data->mlx, data->no_p,
	    &data->img_f.text_width, &data->img_f.text_height);
	data->img_f.south = mlx_xpm_file_to_image(data->mlx, data->so_p,
		&data->img_f.text_width, &data->img_f.text_height);
	data->img_f.east = mlx_xpm_file_to_image(data->mlx, data->ea_p,
		&data->img_f.text_width, &data->img_f.text_height);
	data->img_f.west = mlx_xpm_file_to_image(data->mlx, data->we_p,
		&data->img_f.text_width, &data->img_f.text_height);
    text_addr(data);
}
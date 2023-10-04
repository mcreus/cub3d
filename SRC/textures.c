/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:44:38 by mcreus            #+#    #+#             */
/*   Updated: 2023/10/03 18:49:01 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void    text_addr(t_data *data)
{
    data->textures[0].addr = mlx_get_data_addr(data->textures[0].mlx_img,
            &data->textures[0].bpp,
            &data->textures[0].line_len, &data->textures[0].endian);
    data->textures[1].addr = mlx_get_data_addr(data->textures[1].mlx_img,
            &data->textures[1].bpp,
            &data->textures[1].line_len, &data->textures[1].endian);
    data->textures[2].addr = mlx_get_data_addr(data->textures[2].mlx_img,
            &data->textures[2].bpp,
            &data->textures[2].line_len, &data->textures[2].endian);
    data->textures[3].addr = mlx_get_data_addr(data->textures[3].mlx_img,
            &data->textures[3].bpp,
            &data->textures[3].line_len, &data->textures[3].endian);
}

void    textures(t_data *data)
{
    data->textures[0].mlx_img = mlx_xpm_file_to_image(data->mlx, data->no_p,
            &data->textures[0].text_width, &data->textures[0].text_height);
	if (!(data->textures[0].mlx_img))
		ft_putstr_fd("Error, Texture \n", 2);
    data->textures[1].mlx_img = mlx_xpm_file_to_image(data->mlx, data->so_p,
            &data->textures[1].text_width, &data->textures[1].text_height);
	if (!(data->textures[1].mlx_img))
		ft_putstr_fd("Error, Texture \n", 2);
    data->textures[2].mlx_img = mlx_xpm_file_to_image(data->mlx, data->ea_p,
            &data->textures[2].text_width, &data->textures[2].text_height);
	if (!(data->textures[2].mlx_img))
		ft_putstr_fd("Error, Texture \n", 2);
    data->textures[3].mlx_img = mlx_xpm_file_to_image(data->mlx, data->we_p,
            &data->textures[3].text_width, &data->textures[3].text_height);
	if (!(data->textures[3].mlx_img))
		ft_putstr_fd("Error, Texture \n", 2);
    text_addr(data);
}
void	img_init(t_data *data)
{
	if (data->ray.side == 0 && data->ray.mapx < data->x)
			data->img_f.text_dir = 0;
	if (data->ray.side == 0 && data->ray.mapx >= data->x)
			data->img_f.text_dir = 1;
	if (data->ray.side == 1 && data->ray.mapy < data->y)
			data->img_f.text_dir = 2;
	if (data->ray.side == 1 && data->ray.mapy >= data->y)
			data->img_f.text_dir = 3;
	if (data->ray.side == 0)
                data->img_f.wall_x = data->y + data->ray.perp_wall_dist \
                                                * data->ray.ray_diry;
        else
                data->img_f.wall_x = data->x + data->ray.perp_wall_dist \
                                                * data->ray.ray_dirx;
        data->img_f.wall_x -= floor((data->img_f.wall_x));
}

void    ft_draw_texture(t_data *data, int x, int y)
{
        
        y = data->ray.draw_start - 1;
        img_init(data);
        data->ray.step = 1.0 * data->textures[0].text_height / data->ray.line_height;
        data->img_f.text_x = (int)(data->img_f.wall_x * (double)data->textures[data->img_f.text_dir].text_width);
        if (data->ray.side == 0 && data->ray.ray_dirx > 0)
                data->img_f.text_x = data->textures[data->img_f.text_dir].text_width -    data->img_f.text_x - 1;
        if (data->ray.side == 1 && data->ray.ray_diry < 0)
                data->img_f.text_x = data->textures[data->img_f.text_dir].text_width -  data->img_f.text_x - 1;
        data->img_f.text_pos = (data->ray.draw_start - data->ry / 2 +  data->ray.line_height / 2) * data->ray.step;
        //printf("--------x = %d - ",  x);
        //printf("--------y = %d - ",  y);
        printf("-------------data->ray.draw_start = %d - ",  data->ray.draw_start);
        printf("---------   data->ray.draw_start) = %d \n",  data->ray.draw_end);
        while (++y <= data->ray.draw_end)
        {

                data->img_f.text_y = (int)data->img_f.text_pos & (data->textures[data->img_f.text_dir].text_height - 1);
                data->img_f.text_pos += data->ray.step;
                if (y < data->ry && x < data->rx)
                {
                        data->img_f.addr[y * data->img_f.line_len / 4 + x] =  data->textures[data->img_f.text_dir].addr[data->img_f.text_y *                                        data->textures[data->img_f.text_dir].line_len /                                        4 + data->img_f.text_x];

                        //           
                }
                //mlx_pixel_put(data->mlx, data->win, x, y, 16711680);
        }
        
      // 
}
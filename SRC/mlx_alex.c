/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_alex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:45:41 by aperrein          #+#    #+#             */
/*   Updated: 2023/09/22 14:06:18 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;
	int		i;

	i = img->bpp - 8;
    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		/* big endian, MSB is the leftmost bit */
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		/* little endian, LSB is the leftmost bit */
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int     view(t_data *data)
{
    int     i;
    int     j;
    int     ceil;
    int     floo;

    i = 0;
    ceil = (data->ceiling.r << 16 | data->ceiling.g << 8 | data->ceiling.b);
    floo = (data->floor.r << 16 | data->floor.g << 8 | data->floor.b);
    if (!data->win)
        return (1);
    while (i < (HEIGHT / 2))
	{
		j = 0;
		while (j < WIDTH)
		{
			img_pix_put(&data->img_f, j++, i, ceil);
		}
		++i;
	}
    while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			img_pix_put(&data->img_f, j++, i, floo);
		}
		++i;
	}
    mlx_put_image_to_window(data->mlx, data->win, data->img_f.mlx_img, 0, 0);
    return (0);

}

void    game_init(t_data *data)
{
    data->mlx = mlx_init();
    if (!data->mlx)
		return ;
    data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3d");
    if (!data->win)
		return ;
	
    data->img_f.mlx_img = mlx_new_image(data->mlx,WIDTH , HEIGHT);
    data->img_f.addr = mlx_get_data_addr(data->img_f.mlx_img, &data->img_f.bpp,
                &data->img_f.line_len, &data->img_f.endian);


    mlx_loop_hook(data->mlx, &view, data);
	//mlx_hook(data->win, 17, 0, &end_window, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, &handle_input, data);
	mlx_loop(data->mlx);
	mlx_destroy_image(data->mlx, data->img_f.mlx_img);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}
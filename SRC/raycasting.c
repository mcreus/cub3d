/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:45:41 by aperrein          #+#    #+#             */
/*   Updated: 2023/10/04 17:44:04 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	background(t_data *data)
{
	int		i;
	int		j;
	int		ceil;
	int		floo;

	i = 0;
	ceil = (data->ceiling.r << 16 | data->ceiling.g << 8 | data->ceiling.b);
	floo = (data->floor.r << 16 | data->floor.g << 8 | data->floor.b);
	while (i < (HEIGHT / 2))
	{
		j = 0;
		while (j < WIDTH)
			img_pix_put(&data->img, j++, i, ceil);
		++i;
	}
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
			img_pix_put(&data->img, j++, i, floo);
		++i;
	}
}

void	raycasting(t_data *data)
{
	data->ray.var_x = 0;
	while (data->ray.var_x < WIDTH)
	{
		raycasting1(data);
		raycasting2(data);
		raycasting3(data);
		raycasting4(data);
		raycasting5(data);
		data->texture.tex_pos = (data->ray.draw_start - HEIGHT / 2
				+ data->ray.line_height / 2) * data->texture.step;
		while (data->ray.draw_start < data->ray.draw_end)
		{
			texture_choice(data);
			img_pix_put(&data->img, data->ray.var_x,
				data->ray.draw_start++, data->texture.color);
		}
		data->ray.var_x++;
	}
}

int	view(t_data *data)
{
	if (!data->win)
		return (1);
	background(data);
	raycasting(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.mlx_img, 0, 0);
	ft_moves_ws(data);
	ft_moves_ad(data);
	ft_rotate1(data);
	return (0);
}

void	game_init(t_data *data)
{
	data->mlx = mlx_init();
	init_ray(data);
	if (!data->mlx)
		return ;
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3d");
	if (!data->win)
		return ;
	data->img.mlx_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	img_init(data);
	mlx_loop_hook(data->mlx, &view, data);
	mlx_hook(data->win, DestroyNotify, ButtonPressMask, &ft_finish, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, &handle_input, data);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask,
		&handle_input_release, data);
	mlx_loop(data->mlx);
	mlx_destroy_image(data->mlx, data->img.mlx_img);
	mlx_destroy_image(data->mlx, data->img_ea.mlx_img);
	mlx_destroy_image(data->mlx, data->img_n.mlx_img);
	mlx_destroy_image(data->mlx, data->img_so.mlx_img);
	mlx_destroy_image(data->mlx, data->img_we.mlx_img);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}

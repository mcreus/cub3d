/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:44:38 by mcreus            #+#    #+#             */
/*   Updated: 2023/10/03 09:58:40 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
    data->textures[1].mlx_img = mlx_xpm_file_to_image(data->mlx, data->so_p,
            &data->textures[1].text_width, &data->textures[1].text_height);
    data->textures[2].mlx_img = mlx_xpm_file_to_image(data->mlx, data->ea_p,
            &data->textures[2].text_width, &data->textures[2].text_height);
    data->textures[3].mlx_img = mlx_xpm_file_to_image(data->mlx, data->we_p,
            &data->textures[3].text_width, &data->textures[3].text_height);
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
        data->img_f.text_x = (int)(data->img_f.wall_x * (double)data->textures
                        [data->img_f.text_dir].text_width);
        if (data->ray.side == 0 && data->ray.ray_dirx > 0)
                data->img_f.text_x = data->textures[data->img_f.text_dir].text_width -
                        data->img_f.text_x - 1;
        if (data->ray.side == 1 && data->ray.ray_diry < 0)
                data->img_f.text_x = data->textures[data->img_f.text_dir].text_width -
                        data->img_f.text_x - 1;
        data->img_f.text_pos = (data->ray.draw_start - data->ry / 2 +
                        data->ray.line_height / 2) * data->ray.step;
        while (++y <= data->ray.draw_end)
        {
                data->img_f.text_y = (int)data->img_f.text_pos &
                        (data->textures[data->img_f.text_dir].text_height - 1);
                data->img_f.text_pos += data->ray.step;
                if (y < data->ry && x < data->rx)
                        data->img_f.addr[y * data->img_f.line_len / 4 + x] =
                                data->textures[data->img_f.text_dir].addr[data->img_f.text_y *
                                        data->textures[data->img_f.text_dir].line_len /
                                        4 + data->img_f.text_x];
        }
}

/*int             ft_color_column(t_data *data)
{
        int j;
        int i;

        j = -1;
        data->ray.draw_end = data->ry - data->ray.draw_start;
        i = data->ray.draw_end;
        while (++j < data->ray.draw_start)
                data->img_f.addr[j * data->img_f.line_len / 4 +
                        data->ray.x] = data->c;
        if (j <= data->ray.drawend)
                ft_draw_texture(data, data->ray.x, j);
        j = i;
        while (++j < data->ry)
                data->data.addr[j * data->data.line_length / 4 +
                        data->ray.x] = data->f;
        return (0);
}*/

/*int             ft_raycasting(t_data *data)
{
        data->ray.x = 0;
        while (data->ray.x < data->rx)
        {
                ft_initialisation3(data);
                ft_stepsidedist(data);
                ft_color_column(data);
                data->s.zbuffer[data->ray.x] = data->ray.perpwalldist;
                data->ray.x++;
        }
        ft_sprite(data);
        if (data->save == 1)
                ft_save(data);
        mlx_put_image_to_window(data->data.mlx_ptr, data->data.mlx_win,
                        data->data.img, 0, 0);
        ft_forward_back(data);
        ft_left_right(data);
        ft_rotate_right_left(data);
        ft_swap(data);
        return (0);
}*/

/*int ft_path_texture(char *str, char **texture, t_data *data, int j)
{
        data->count = 0;
        if (*texture != NULL)
        {
                data->conf_error = 1;
                return (0);
        }
        if (check(str, '.') == 0 || check(str, '/') == 0
                        || ft_strlen(str) <= 2)
                data->conf_error = 1;
        while (str[j] != '.')
        {
                if (str[j] != ' ' && str[j] != '.')
                        data->conf_error = 2;
                j++;
        }
        if (!(*texture = (char *)(malloc(sizeof(char) * (ft_strlen(str) + 1)))))
                data->conf_error = 2;
        while (str[j] != '\0')
        {
                (*texture)[data->count] = str[j];
                data->count++;
                j++;
        }
        (*texture)[data->count] = '\0';
        return (0);
}

static int	check(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

void    ft_texture(char *str, t_data *data)
{
        int                     i;
        static int      j = 0;

        i = 0;
        if (str[i] == 'S' && str[i + 1] == 'O')
                ft_path_texture(str, &data->no, data, 2);
        else if (str[i] == 'N' && str[i + 1] == 'O')
                ft_path_texture(str, &data->so, data, 2);
        else if (str[i] == 'E' && str[i + 1] == 'A')
                ft_path_texture(str, &data->we, data, 2);
        else if (str[i] == 'W' && str[i + 1] == 'E')
                ft_path_texture(str, &data->ea, data, 2);
        else if (str[i] == 'S' && str[i + 1] != 'O')
                ft_path_texture(str, &data->sp, data, 1);
        else if (str[0] != 'N' && str[0] != 'S' && str[0] != 'W' && str[0] != 'E'
                        && str[0] != 'R' && str[0] != 'F' && str[0] != 'C'
                        && str[0] > 65 && str[0] < 122)
                data->erreur = 2;
        j++;
}*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:43:15 by aperrein          #+#    #+#             */
/*   Updated: 2023/10/02 18:46:44 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <X11/X.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

# define WIDTH 3200
# define HEIGHT 1000

typedef struct s_color
{
	char	*name;
	int		r;
	int		g;
	int		b;
}				t_color;

typedef struct s_img
{
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	void		*north;
	void		*south;
	void		*east;
	void		*west;
	int			text_width;
	int			text_height;
	double		text_pos;
	double 		wall_x;
	int			text_x;
	int			text_y;
	int			text_dir;
}	t_img;

typedef struct s_moves
{
	int		move_forward;
	int		move_back;
	int		step_to_left;
	int		step_to_right;
	int		rotate_left;
	int		rotate_right;
	double	move_speed;
	double	rotate_speed;
}	t_moves;

typedef struct s_ray
{
	double	camerax;
	double	ray_dirx;
	double	ray_diry;
	double	ray_dirx0;
	double	ray_diry0;
	double	ray_dirx1;
	double	ray_diry1;
	double	side_distx;
	double	side_disty;
	double	delta_distx;
	double	delta_disty;
	double	perp_wall_dist;
	int		mapx;
	int		mapy;
	double	step;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			file_lenght;
	int			configured;
	int			conf_error;
	int			map_error;
	int			nbr_player;
	int			error_wall;
	int			count;
	int			no;
	int			so;
	int			we;
	int			ea;
	int			fl;
	int			ce;
	int			rx;
	int			ry;
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		plan_x;
	double		plan_y;
	double		p_angle;
	char		**file;
	char		**map;
	char		**clone;
	char		*no_p;
	char		*so_p;
	char		*we_p;
	char		*ea_p;
	char		start_player;
	t_color		floor;
	t_color		ceiling;
	t_img		img_f;
	t_img		textures[4];
	t_moves		moves;
	t_ray		ray;
}				t_data;

int			conf_init(int argc, char *argv[], t_data *data);
int			check_color(t_color *color);
int			cub_check(char *s);
int			empty_line(char *s);
int			error(char *s);
int			ft_finish(t_data *data);
char		**clone(t_data *data);
void		select_identifier2(t_data *data, char **line);
void		recup_element(t_data *data, char *s);

void		free_error(t_data *data, char *s);
void		conf_check(t_data *data);
void		check_map(t_data *data);
void		free_tab(char **tab);
void		game_init(t_data *data);
/*test raytracing*/
int			mlx_destroy(t_data *data);
int			handle_input(int keysym, t_data *data);
int			ft_finish(t_data *data);
void    ft_draw_texture(t_data *data, int x, int y);
void	img_init(t_data *data);
void    textures(t_data *data);
void    text_addr(t_data *data);

/*MOVES*/
void		ft_moves_ws(t_data *data);
void		ft_moves_ad(t_data *data);
void		ft_rotate1(t_data *data);
void		ft_rotate2(t_data *data);
void		moves(int nb, t_data *data);
void		init_ray(t_data *data);
int			handle_input_release(int keysym, t_data *data);
void		img_init(t_data *data);
int			ft_path_texture(char *str, char **texture, t_data *data, int j);

#endif

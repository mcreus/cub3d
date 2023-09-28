/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:43:15 by aperrein          #+#    #+#             */
/*   Updated: 2023/09/28 19:08:28 by mcreus           ###   ########.fr       */
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
# define HEIGHT 900
# define TEXTURE 50

typedef struct s_color
{
	char	*name;
	int		r;
	int		g;
	int		b;
}				t_color;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
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

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*north;
	void		*south;
	void		*east;
	void		*west;
	int			file_lenght;
	int			configured;
	int			conf_error;
	int			map_error;
	int			nbr_player;
	int			error_wall;
	double		x;
	double		y;
	double		pos_x;
	double		pos_y;
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
	t_moves		moves;
}				t_data;

int			conf_init(int argc, char *argv[], t_data *data);
int			check_color(t_color *color);
int			cub_check(char *s);
int			empty_line(char *s);
int			error(char *s);
int			ft_finish(t_data *data);
char		**clone(t_data *data);

void		free_error(t_data *data, char *s);
void		conf_check(t_data *data);
void		check_map(t_data *data);
void		free_tab(char **tab);
void		game_init(t_data *data);
/*test raytracing*/
int			mlx_destroy(t_data *data);
int			handle_input(int keysym, t_data *data);
/*MOVES*/
void		init_ray(t_data *data);
void		ft_moves_ws(t_data *data);
void		ft_moves_ad(t_data *data);
void		ft_rotate1(t_data *data);
void		ft_rotate2(t_data *data);
void		moves(int nb, t_data *data);
void		init_ray(t_data *data);
int			handle_input_release(int keysym, t_data *data);

#endif

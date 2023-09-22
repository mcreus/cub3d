/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:43:15 by aperrein          #+#    #+#             */
/*   Updated: 2023/09/20 10:54:59 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

# define WIDTH 3200
# define HEIGHT 1800
# define textWidth 50
# define textHeight 50

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

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*north;
	void	*south;
	void	*east;
	void	*west;
	int		x;
	int		y;
	int		p_x;
	int		p_y;
	int		file_lenght;
	int		configured;
	int		conf_error;
	char	**file;
	char	**map;
	char	*no_p;
	char	*so_p;
	char	*we_p;
	char	*ea_p;
	t_color		floor;
	t_color		ceiling;
	t_img		img_f;
}				t_data;

int	conf_init(int argc, char *argv[], t_data *data);
int	check_color(t_color *color);
int	cub_check(char *s);
int	empty_line(char *s);
int	error(char *s);
void		free_error(t_data *data, char *s);
void		conf_check(t_data *data);
void		free_tab(char **tab);
void    	game_init(t_data *data);

#endif

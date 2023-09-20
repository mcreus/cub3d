/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:43:15 by aperrein          #+#    #+#             */
/*   Updated: 2023/09/20 17:57:57 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

# define width 500
# define height 500
# define textWidth 50
# define textHeight 50
# define PI 3.14
# define P2 PI / 2
# define P3 3 * PI / 2

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
	float		p_x;
	float		p_y;
	int		file_lenght;
	int		configured;
	int		conf_error;
	char	**file;
	char	**map;
	char	*no_p;
	char	*so_p;
	char	*we_p;
	char	*ea_p;
	char	*f_p;
	char	*c_p;
}				t_data;

int	conf_init(int argc, char *argv[], t_data *data);
int	cub_check(char *s);
int	empty_line(char *s);
int	error(char *s);
void		free_error(t_data *data, char *s);
void		conf_check(t_data *data);
void		free_tab(char **tab);



void	init_screen(t_data *data);
void	draw_player(t_data *data);
void draw_square(void *mlx, void *win, int x, int y, int size, int color);
void	keys(unsigned char key, int x, int y);
int	mlx_destroy(t_data *data);
int	handle_input(int keysym);
void	draw_2d(void *mlx, void *win);
void draw_square2(void *mlx_ptr, void *win_ptr, int x, int y, int color);
#endif

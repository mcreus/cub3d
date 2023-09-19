/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:43:15 by aperrein          #+#    #+#             */
/*   Updated: 2023/09/19 17:28:02 by mcreus           ###   ########.fr       */
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
# define mapWidth 50
# define mapHeight 50

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
	int		file_lenght;
	int		configured;
	int		conf_error;
	int		fd;
	int		lines;
	int		columns;
	char	**file;
	char	**map;
	char	*no_p;
	char	*so_p;
	char	*we_p;
	char	*ea_p;
	char	*f_p;
	char	*c_p;
}				t_data;

int	map_init(int argc, char *argv[], t_data *data);
int	cub_check(char *s);
int	empty_line(char *s);
int	error(char *s);
void		free_error(t_data *data, char *s);
void		conf_check(t_data *data);
void		free_tab(char **tab);

#endif

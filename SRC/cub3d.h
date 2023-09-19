#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		file_lenght;
	int		configured;
	int		conf_error;
	char	**file;
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
}				t_data;


int		main();
int	map_init(int argc, char *argv[], t_data *data);
int	cub_check(char *s);
int	empty_line(char *s);
int	error(char *s);
void	free_error(t_data *data, char *s);
void    conf_check(t_data *data);
void    free_tab(char **tab);

#endif
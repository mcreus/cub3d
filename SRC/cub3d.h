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
	char	**file;
}				t_data;


int		main();
int	map_init(int argc, char *argv[], t_data *data);
int	cub_check(char *s);
int	error(char *s);
void	free_error(t_data *data, char *s);

#endif
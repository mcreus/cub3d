#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
}				t_data;


int		main();

#endif
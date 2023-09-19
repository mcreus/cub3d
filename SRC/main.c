/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:57:11 by mcreus            #+#    #+#             */
/*   Updated: 2023/09/05 15:17:54 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	keysym(int key, void *param)
{
	ft_putchar('x');
	(void)key;
	(void)param;
	return (0);
}

int main(int argc, char *argv[])
{
	t_data  data;
	
	map_init(argc, argv, &data);
	//data.mlx = mlx_init();
	//data.win = mlx_new_window(data.mlx, 500, 500, "new project");
	//mlx_key_hook(data.win, keysym, (void *)0);
	//mlx_loop(data.mlx);
	if (data.file)
		free_error(&data, "Fin du jeu\n");
}
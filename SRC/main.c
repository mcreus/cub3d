/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:57:11 by mcreus            #+#    #+#             */
/*   Updated: 2023/09/19 17:59:07 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	keysym(int key, void *param)
{
	ft_putchar_fd('x', 1);
	(void)key;
	(void)param;
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	conf_init(argc, argv, &data);
	//data.mlx = mlx_init();
	//data.win = mlx_new_window(data.mlx, 500, 500, "new project");
	//mlx_key_hook(data.win, keysym, (void *)0);
	//mlx_loop(data.mlx);
	if (data.file)
		free_error(&data, "Fin du jeu\n");
}

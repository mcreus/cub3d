/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:57:11 by mcreus            #+#    #+#             */
/*   Updated: 2023/09/22 10:08:26 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	conf_init(argc, argv, &data);
	//init_screen(&data);
	//data.mlx = mlx_init();
	//data.win = mlx_new_window(data.mlx, 500, 500, "new project");
	//mlx_key_hook(data.win, keysym, (void *)0);
	//mlx_loop(data.mlx);
	game_init(&data);
	if (data.file)
		free_error(&data, "Fin du jeu\n");
}

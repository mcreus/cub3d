/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_conf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:46:21 by aperrein          #+#    #+#             */
/*   Updated: 2023/09/18 15:17:36 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

int	error(char *s)
{
	ft_printf("%s\n", s);
	return (0);
}

void	free_error(t_data *data, char *s)
{
	int	i;

	i = 0;
	while (i < data->file_lenght)
		free(data->file[i++]);
	free(data->file);
	data->file = NULL;
	ft_printf("%s", s);
}

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

void	free_data(t_data *data)
{
	if (data->c_p)
		free(data->c_p);
	if (data->f_p)
		free(data->f_p);
	if (data->no_p)
		free(data->no_p);
	if (data->we_p)
		free(data->we_p);
	if (data->ea_p)
		free(data->ea_p);
	if (data->so_p)
		free(data->so_p);
	free_tab(data->file);
	data->file = 0;
	free_tab(data->map);
	data->map = 0;
}

void	free_error(t_data *data, char *s)
{
	free_data(data);
	ft_printf("%s", s);
}

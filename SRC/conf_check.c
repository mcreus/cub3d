/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 09:41:20 by aperrein          #+#    #+#             */
/*   Updated: 2023/09/29 11:31:50 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	select_identifier(t_data *data, char **line)
{
	if (!ft_strncmp(line[0], "NO", 2))
	{
		data->no_p = ft_strtrim(line[1], "\n");
		data->no += 1;
	}
	else if (!ft_strncmp(line[0], "SO", 2))
	{
		data->so_p = ft_strtrim(line[1], "\n");
		data->so += 1;
	}
	else if (!ft_strncmp(line[0], "WE", 2))
	{
		data->we_p = ft_strtrim(line[1], "\n");
		data->we += 1;
	}
	else if (!ft_strncmp(line[0], "EA", 2))
	{
		data->ea_p = ft_strtrim(line[1], "\n");
		data->ea += 1;
	}
	else
		select_identifier2(data, line);
}

void	select_identifier2(t_data *data, char **line)
{
	if (!ft_strncmp(line[0], "F", 1))
	{
		data->floor.name = ft_strtrim(line[1], "\n");
		data->fl = 1;
	}
	else if (!ft_strncmp(line[0], "C", 1))
	{
		data->ceiling.name = ft_strtrim(line[1], "\n");
		data->ce = 1;
	}
	else if (!data->configured)
		data->conf_error = 1;
	if (data->no == 2 || data->so == 2 || data->we == 2 || data->ea == 2
		|| data->fl == 2 || data->ce == 2)
		data->conf_error = 1;
}

void	recup_element(t_data *data, char *s)
{
	char	**line;
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strtrim(s, "\n");
	line = ft_split(tmp, ' ');
	free(tmp);
	while (line[i])
		i++;
	if (i != 2 && !data->configured)
	{
		data->conf_error = 1;
		free_tab(line);
		return ;
	}
	select_identifier(data, line);
	if (data->no_p && data->so_p && data->we_p && data->ea_p \
		&& data->floor.name && data->ceiling.name)
		data->configured = 1;
	free_tab(line);
}

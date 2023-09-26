/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:14:27 by aperrein          #+#    #+#             */
/*   Updated: 2023/09/25 13:39:05 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cub_check(char *s)
{
	char	*ext;

	ext = ft_strrchr(s, '.');
	if (!ext)
		return (0);
	if (ft_strncmp(ext, ".cub", 5) != 0)
		return (0);
	return (1);
}

int	empty_line(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int	ft_count_lines(t_data *data)
{
	int		i;
	char	*str;

	i = 0;
	while (1)
	{
		str = get_next_line(data->map[data->y][data->x]);
		if (!str)
			break ;
		free(str);
		i++;
	}
	free (str);
	return (i);
}

void	dup_map(t_data *data)
{
	int	i;

	i = 0;
	data->map_dup = ft_calloc(data->lines + 1, sizeof(char *));
	while (i < data->lines)
	{
		data->map_dup[i] = ft_strdup(data->map[i]);
		i++;
	}
}
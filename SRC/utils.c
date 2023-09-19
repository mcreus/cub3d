/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:14:27 by aperrein          #+#    #+#             */
/*   Updated: 2023/09/19 13:14:49 by aperrein         ###   ########.fr       */
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

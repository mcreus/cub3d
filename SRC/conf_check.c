/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 09:41:20 by aperrein          #+#    #+#             */
/*   Updated: 2023/09/20 11:05:02 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    select_identifier(t_data *data, char **line)
{
    if (!ft_strncmp(line[0], "NO", 2))
        data->no_p = ft_strdup(line[1]);
    else if (!ft_strncmp(line[0], "SO", 2))
        data->so_p = ft_strdup(line[1]);
    else if (!ft_strncmp(line[0], "WE", 2))
        data->we_p = ft_strdup(line[1]);
    else if (!ft_strncmp(line[0], "EA", 2))
        data->ea_p = ft_strdup(line[1]);
    else if (!ft_strncmp(line[0], "F", 1))
        data->f_p = ft_strdup(line[1]);
    else if (!ft_strncmp(line[0], "C", 1))
        data->c_p = ft_strdup(line[1]);
    else if (!data->configured)
        data->conf_error = 1;
}

void    recup_element(t_data *data, char *s)
{
    char    **line;
    int i;

    i = 0;
    line = ft_split(s,' ');
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
        && data->f_p && data->c_p)
        data->configured = 1;
    free_tab(line);
}

int     element_check(t_data *data)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (i < data->file_lenght && !data->configured)
    {
        if (!empty_line(data->file[i]))
            recup_element(data, data->file[i]);
        i++;
    }
    while (i < data->file_lenght && empty_line(data->file[i]))
        i++;
    data->map = malloc(sizeof(char *) * (data->file_lenght - i +1));
    while (i < data->file_lenght)
        data->map[j++] = ft_strdup(data->file[i++]);
    data->map[j] = 0;
    if (data->conf_error)
        free_error(data, "Configuration issues\n");
    return (0);
}

void    conf_check(t_data *data)
{
    data->conf_error = 0;
    data->configured = 0;
    data->map = 0;
    data->c_p = 0;
    data->f_p = 0;
    data->no_p = 0;
    data->so_p = 0;
    data->we_p = 0;
    data->ea_p = 0;
    data->x = 0;
    data->y = 0;
    element_check(data);
}

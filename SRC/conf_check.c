/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 09:41:20 by aperrein          #+#    #+#             */
/*   Updated: 2023/09/19 09:41:41 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    select_identifier(t_data *data, char **line)
{
    if (!ft_strncmp(line[0], "NO", 2))
        ft_printf("%s\n", line[0]);
    (void)data;
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
        return ;
    }
    select_identifier(data, line);
    free_tab(line);
}

int     element_check(t_data *data)
{
    int i;

    i = 0;
    while (i < data->file_lenght)
    {
        if (!empty_line(data->file[i]))
            recup_element(data, data->file[i]);
        i++;
    }
    return (0);
}

void    conf_check(t_data *data)
{
    data->conf_error = 0;
    data->configured = 0;
    element_check(data);
}
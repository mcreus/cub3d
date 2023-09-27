/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:46:16 by aperrein          #+#    #+#             */
/*   Updated: 2023/09/26 13:46:39 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    check_init_pos(char c, t_data *data)
{
    if (c == ' ' || c == '1' || c == '0')
        return ;
    data->start_player = c;
    data->nbr_player++;
}

void    check_player(t_data *data)
{
    int     i;
    int     j;
    char    c;

    j = 0;
    while (data->map[j])
    {
        i = 0;
        while (data->map[j][i])
        {
            c = data->map[j][i];
            if (c == '0' || c == '1' || c == ' ' || c == 'N'
                || c == 'W' || c == 'S' || c == 'E')
                check_init_pos(c, data);
            else
                data->map_error = 1;
            i++;
        }
        j++;
    }
}

void    check_map(t_data *data)
{
        data->nbr_player = 0;
        data->map_error = 0;
        check_player(data);
}
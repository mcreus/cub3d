/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:22:31 by aperrein          #+#    #+#             */
/*   Updated: 2023/09/22 18:39:11 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	file_check(int argc, char *file)
{
	if (argc == 1)
		return (error("Error\nArg missing"));
	if (argc > 2)
		return (error("Error\nToo many args"));
	if (!cub_check(file))
		return (error("Error\nMap must be a .cub"));
	return (1);
}

int	line_nb(char *s, t_data *data)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(s, O_RDONLY);
	if (fd == -1)
		return (error("No such file or directory"));
	line = get_next_line(fd);
	if (line)
		data->file_lenght = (int)ft_strlen(line) - 1;
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

void	conf_fill(char *file, t_data *data)
{
	int	i;
	int	fd;

	fd = open(file, O_RDONLY);
	i = 0;
	while (i < data->file_lenght)
	{
		data->file[i] = get_next_line(fd);
		if (data->file[i] == '1' && data->file[i + 1] == '1') /*check begin of map*/
			data->map[0] = data->file[i]; /*ajout max*/
		i++;
	}
	data->file[i] = 0;
	close(fd);
}

void	conf_read(char *s, t_data *data)
{
	data->file_lenght = line_nb(s, data);
	if (!data->file_lenght)
		return ;
	data->file = malloc(sizeof(char *) * (data->file_lenght +1));
	if (data->file)
		conf_fill(s, data);
	if (!data->file_lenght)
		free_error(data, "Error\nThe file is empty\n");
}

int	conf_init(int argc, char *argv[], t_data *data)
{
	data->file = 0;
	data->conf_error = 0;
	data->configured = 0;
	data->map = 0;
	if (!file_check(argc, argv[1]))
		return (0);
	conf_read(argv[1], data);
	conf_check(data);
	return (1);
}

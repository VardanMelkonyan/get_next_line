/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmelkony <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 18:23:41 by vmelkony          #+#    #+#             */
/*   Updated: 2021/04/21 18:48:25 by vmelkony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*only_last_line(char *str)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	while(str[i] && str[i] != '\n')
		i++;
	result = malloc(sizeof(char) * (ft_strlen(str) - 1));
	if (!result)
		return (0);
	i++;
	j = 0;
	while (str[i])
		result[j++] = str[i++];
	result[j] = '\0';
	free(save);
	return (result);
}

char	*save_cpy(char *str)
{
	char	*result;
	int		i;

	i = 0;
	while (!str)
		return (0);
	while(str[i] && str[i] != '\n')
		i++;
	result = malloc(sizeof(char) * i);
	if (!result)
		return (0);
	i = 0;
	while(str[i] && str[i] != '\n')
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int		get_next_line(int fd, char **line)
{
	char *buffer;
	static char *save;
	int reader;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (-1);
	reader = 1;
	while (!has_next_line(save) && reader != 0)
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		if (reader == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[reader] = '\0';
		ft_strjoin(save, buffer);	
	}
	free(buffer);
	*line = save_cpy(save);
	save = only_last_line(save);
	if (reader == 0)
		return (0);
	return (1);
}

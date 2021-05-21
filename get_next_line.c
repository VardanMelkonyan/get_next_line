#include "get_next_line.h"

char	*only_last_line(char *str)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	if (!str)
		return(NULL);
	while(str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return(NULL);
	}
	result = malloc(sizeof(char) * (ft_strlen(str) -1 ));
	if (!result)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		result[j++] = str[i++];
	result[j] = '\0';
	free(str);
	return (result);
}

char	*save_cpy(char *str)
{
	char	*result;
	int		i;

	i = 0;
	while(str && str[i] != '\n' && str[i] != '\0')
		i++;
	result = malloc(sizeof(char) * i);
	if (!result)
		return (NULL);
	i = 0;
	while(str && str[i] != '\n' && str[i] != '\0')
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
	if(!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	reader = 1;
	while ((reader = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[reader] = '\0';
		save = ft_strjoin(save, buffer);
		if (ft_strchr(save, '\0') || ft_strchr(save, '\n'))
			break;
	}
	free(buffer);
	if (reader < 0)
		return (-1);
	*line = save_cpy(save);
	save = only_last_line(save);
	if (reader == 0 && !save)
		return (0);
	return (1);
}

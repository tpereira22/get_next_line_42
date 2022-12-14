#include "get_next_line.h"

char    *ft_savenextline(char *save)
{
    char    *buff;
    int     i;
    int     j;

    i = 0;
    while (save[i] && save[i] != 10)
        i++;
    if (!save[i] || !save[i + 1])
    {
        free(save);
        return (NULL);
    }
    i++;
    buff = malloc(sizeof(char) * ((ft_strlen(save) - i) + 1));
    if (!buff)
        return (NULL);
    j = 0;
    while (save[i] != '\0')
        buff[j++] = save[i++];
    buff[j] = '\0';
    free(save);
    return (buff);
}

char    *ft_copyline(char *save)
{
    char    *buff;
    int     i;

    i = 0;
    if (!save[i])
        return (NULL);
    while (save[i] && save[i] != 10)
        i++;
    buff = malloc(sizeof(char) * (i + 2));
    if (!buff)
        return (NULL);
    i = 0;
	while (save[i] && save[i] != '\n')
	{
		buff[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
    {
    	buff[i] = save[i];
        i++;
    }
    buff[i] = '\0';
    return (buff);
}

char	*ft_readtosave(int fd, char *save)
{
	char	*buff;
	int		bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	bytes = 1;
	while (bytes != 0 && !ft_strchr(save, 10))
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buff);
			return (NULL);
		}
        buff[bytes] = '\0';
        if (bytes > 0)
		    save = ft_strjoin(save, buff);
    }
    free(buff);
	return (save);
}


char    *get_next_line(int fd)
{
    static char *buff_save[1024];
    char        *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    buff_save[fd] = ft_readtosave(fd, buff_save[fd]);
    if (!buff_save[fd])
        return (NULL);
    line = ft_copyline(buff_save[fd]);
    buff_save[fd] = ft_savenextline(buff_save[fd]);
    return (line);
}

/*int	main(void)
{
	int		fd;
	static char	*str;
	int		i;

	i = 1;
	fd = open("text", O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		printf("Line %i: %s", i, str);
		if (!str)
			break ;
		free(str);
		i++;
	}
}*/
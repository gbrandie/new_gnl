#include "get_next_line.h"

char	*remainder_checker(char **remainder, char *p_n)
{
	char	*temp;
	char	*line;

	if (!p_n)
	{
		line = ft_strdup(*remainder);
		free(*remainder);
		*remainder = NULL;
		return (line);
	}
	*p_n = '\0';
	p_n++;
	line = ft_strdup_n(*remainder);
	if (!p_n)
	{
		free(*remainder);
		*remainder = NULL;
		return (line);
	}
	temp = ft_strdup(p_n);
	free(*remainder);
	*remainder = temp;
	return (line);
}

char	*read_file(int fd, char *remainder, char *buf)
{
	ssize_t	read_size;

	read_size = 1;
	while (read_size > 0)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		buf[read_size] = '\0';
		remainder = ft_strjoin(remainder, buf);
		if (ft_strchr(remainder, '\n'))
			return (remainder);
	}
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		buf[BUFFER_SIZE + 1];
	char		*p_n;

	if ((BUFFER_SIZE <= 0) || (read(fd, buf, 0) < 0))
		return (NULL);
	remainder = read_file(fd, remainder, buf);
	if (!remainder || ft_strlen(remainder) == 0)
		return (NULL);
	p_n = ft_strchr(remainder, '\n');
	return (remainder_checker(&remainder, p_n));
}

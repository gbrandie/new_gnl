#include "get_next_line.h"

size_t	ft_strlen(const char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *string, int symbol)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == (unsigned char)symbol)
			return (&((char *)string)[i]);
		i++;
	}
	if (symbol == '\0')
		return (&((char *)string)[i]);
	else
		return (NULL);
}

char	*ft_strdup(char *src)
{
	char	*dst;
	size_t		src_len;
	int		i;

	i = 0;
	src_len = ft_strlen(src);
	dst = (char *)malloc((src_len + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char *remainder, char *buf)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!remainder)
		return (ft_strdup(buf));
	result = (char *)
		malloc(sizeof(char) * (ft_strlen(buf) + ft_strlen(remainder) + 1));
	if (!result)
		return (NULL);
	while (remainder[i])
		result[i++] = remainder[j++];
	j = 0;
	while (buf[j])
		result[i++] = buf[j++];
	result[i] = '\0';
	free(remainder);
	return (result);
}

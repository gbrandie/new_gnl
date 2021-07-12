#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif
size_t	ft_strlen(const char *string);
char	*ft_strdup(char *src);
char	*ft_strchr(const char *string, int symbol);
char	*remainder_checker(char **remainder, char *p_n);
char	*ft_strjoin(char *remainder, char *buf);
char	*get_next_line(int fd);
char	*read_file(int fd, char *remainder, char *buf);
char	*ft_strdup_n(char *src);
#endif

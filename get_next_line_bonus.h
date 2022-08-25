#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

char    *get_next_line(int fd);
char    *ft_readtosave(int fd, char *save);
char    *ft_copyline(char *save);
char    *ft_savenextline(char *save);

size_t  ft_strlen(char *str);
char    *ft_strjoin(char *s1, char *s2);
char    *ft_strchr(char *s, int c);

#endif
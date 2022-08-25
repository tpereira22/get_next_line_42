#include "get_next_line.h"

size_t  ft_strlen(char *str)
{
    int i;

    i = 0;
    if (!str)
        return (0);
    while (str[i] != '\0')
        i++;
    return (i);
}

char	*ft_strchr(char *s, int c)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *) s + i);
		i++;
	}
	if (s[i] == (char) c)
		return ((char *) s + i);
	return (NULL);
}

char    *ft_strjoin(char *s1, char *s2)
{
    char    *str;
    size_t     i;
    size_t     j;

    str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!str)
        return (NULL);
    i = 0;
    if (s1)
    {
        while (s1[i] != '\0')
        {
            str[i] = s1[i];
            i++;
        }
    }
    j = 0;
    while (s2[j] != '\0')
        str[i++] = s2[j++];
    str[i] = '\0';
    free(s1);
    return (str);
}
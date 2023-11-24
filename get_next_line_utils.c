#include "get_next_line.h"
char	*ft_strdup(const char *src)
{
	size_t	i;
	char	*sa;

	i = 0;
	sa = (char *)malloc(ft_strlen(src) * sizeof(char) + 1);
	if (!sa)
		return (NULL);
	while (i < ft_strlen(src))
	{
		sa[i] = src[i];
		i++;
	}
	sa[ft_strlen(src)] = 0;
	return (sa);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	int		l;

	i = 0;
	l = ft_strlen(src);
	if (size > 0)
	{
		while (i < size - 1 && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = 0;
	}
	return (l);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest;
	size_t	srcc;
	size_t	i;

	dest = ft_strlen(dst);
	srcc = ft_strlen(src);
	i = 0;
	if (size <= dest)
		return (size + srcc);
	while (src[i] && (i + dest) < size - 1)
	{
		dst[dest + i] = src[i];
		i++;
	}
	dst[dest + i] = 0;
	return (dest + srcc);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (result != NULL)
	{
		ft_strlcpy(result, s1, s1_len + 1);
		ft_strlcat(result, s2, s1_len + s2_len + 1);
	}
	return (result);
}
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}

char* ft_substring(const char* str, int start, int length) {

    if (str == NULL || start < 0 || length < 0) {
        return NULL;
    }

    char* substr = (char*)malloc((length + 1) * sizeof(char));

    if (substr == NULL) {
       return NULL;
    }

   
    ft_strlcpy(substr, str + start, length);

 
    substr[length] = '\0';

    return substr;
}
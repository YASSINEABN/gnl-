/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboulan <yaboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:41:20 by yaboulan          #+#    #+#             */
/*   Updated: 2023/11/25 14:46:40 by yaboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

int	ft_find(char c, char *str)
{
	int	index;

	if (!str)
		return (-1);
	index = 0;
	while (str[index])
	{
		if (str[index] == c)
			return (index);
		index++;
	}
	if (!c && !str[index])
		return (index);
	return (-1);
}

char	*read_into_remainder(int fd, char *remainder, int *new_line)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			break ;
		buffer[bytes_read] = '\0';
		remainder = ft_strjoin(remainder, buffer);
		*new_line = ft_find('\n', remainder);
		if (*new_line >= 0)
			break ;
	}
	free(buffer);
	return (remainder);
}

char	*extract_line(char *remainder, int new_line)
{
	char	*line;
	char	*temp;

	if (!remainder)
		return (NULL);
	if (new_line >= 0)
	{
		temp = ft_substr(remainder, 0, new_line + 1);
		line = ft_strjoin(NULL, temp);
		free(temp);
	}
	else
		line = ft_strjoin(NULL, remainder);
	return (line);
}

char	*process_remainder(char *remainder, int new_line)
{
	char	*temp;

	if (!remainder)
		return (NULL);
	if (new_line < 0)
	{
		free(remainder);
		return (NULL);
	}
	temp = ft_substr(remainder, new_line + 1, ft_strlen(remainder));
	free(remainder);
	remainder = temp;
	return (remainder);
}	

	char	*get_next_line(int fd)
	{
		static char	*remainder;
		char		*line;
		int			new_line;

		if (fd < 0 || BUFFER_SIZE <= 0)
			return (NULL);
		remainder = read_into_remainder(fd, remainder, &new_line);
		if (!remainder)
			return (NULL);
		if (!*remainder)
		{
			free(remainder);
			return (NULL);
		}
		line = extract_line(remainder, new_line);
		remainder = process_remainder(remainder, new_line);
		return (line);
	}
int main(int argc, char const *argv[])
{
	int fd = open("test.txt",O_RDONLY);
	char *s;
	while(s = get_next_line(fd))
	{
		printf("%s",s);
	}
	return 0;
}

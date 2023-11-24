/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboulan <yaboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:50:54 by yaboulan          #+#    #+#             */
/*   Updated: 2023/11/24 22:44:09 by yaboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	checknewline(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*process_remainder(char **remainder)
{
	char	*newline;
	char	*line;
	char	*temp;

	newline = NULL;
	line = NULL;
	if (*remainder)
	{
		   if ((newline = ft_strchr(*remainder, '\n')) != NULL)
        {
            line = ft_substring(*remainder, 0, checknewline(*remainder) + 2);
            newline++;
			temp = ft_strdup(newline);
            free(*remainder);
			*remainder = ft_strdup(temp);
			free(temp);
        }
        
        
		
		else
		{
			line = ft_strdup(*remainder);
			free(*remainder);
			*remainder = NULL;
		}
	}
	
	return (line);	
}

static char	*read_into_remainder(int fd, char **remainder)
{
	char	*buffer;
	int		bytesread;
	char	*newline;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytesread = 0;
	newline = NULL;
	while ((bytesread = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytesread] = 0;
		if (*remainder == NULL)
			*remainder = ft_strdup(buffer);
		else
		{
			
			char *temp = ft_strjoin(*remainder, buffer);
			free(*remainder);
			*remainder=ft_strdup(temp);
			free(temp);
		}
		if ((newline = ft_strchr(*remainder, '\n')) != NULL)
			break ;
	}
	free(buffer);
	return (process_remainder(remainder));
}

char	*get_next_line(int fd)
{
	static char	*remainder = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_into_remainder(fd, &remainder);
	return (line);
}

int	main(int argc, char const *argv[])
{
	int		fd;
	char	*s;

	fd = open("test.txt", O_RDWR);
	while ((s = get_next_line(fd)))
	{
		printf("%s", s);
		free(s);
	}
	while(1);
	return (0);
}

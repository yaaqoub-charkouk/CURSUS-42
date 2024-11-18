/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:56:19 by ycharkou          #+#    #+#             */
/*   Updated: 2024/11/18 16:58:06 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_accumulate(int fd, char *accumulation)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		accumulation = ft_strjoin(accumulation, buffer);
		if (ft_strchr(accumulation, '\n') != -1)
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read == -1)
	{
		free(accumulation);
		accumulation = NULL;
		return (NULL);
	}
	return (accumulation);
}

char	*extract_line(char **accumulation)
{
	char	*line;
	int		nl_index;
	char	*new_accumulation;

	nl_index = ft_strchr(*accumulation, '\n');
	if (nl_index != -1)
	{
		line = ft_substr(*accumulation, 0, nl_index + 1);
		new_accumulation = ft_strdup(*accumulation + nl_index + 1);
		free(*accumulation);
		*accumulation = new_accumulation;
	}
	else
	{
		line = ft_strdup(*accumulation);
		free(*accumulation);
		*accumulation = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*accumulation;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
	{
		free(accumulation);
		accumulation = NULL;
		return (NULL);
	}
	accumulation = read_and_accumulate(fd, accumulation);
	if (!accumulation || !*accumulation)
	{
		free(accumulation);
		accumulation = NULL;
		return (NULL);
	}
	return (extract_line(&accumulation));
}

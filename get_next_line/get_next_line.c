#include "get_next_line.h"

//the function read from the file to buffer , and concatenate to the accumulation
char	*read_and_accumulate(int fd, char *accumulation)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		accumulation = ft_strjoin(accumulation, buffer);
		//break if new line char found
		if (ft_strchr(accumulation, '\n') != -1)
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read == -1)//nchofo wash shiha ? ah shiha
	{
		free(accumulation);
		accumulation = NULL;
		return (NULL);
	}
	return (accumulation);
}
//if newline found ,  return the line and update the static accumulation
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
		//update accumulation after freeing it , that way it will continue reading in the next func call .
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

char *get_next_line(int fd)
{
	static char	*accumulation;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
	{
		free(accumulation);
		accumulation = NULL;
		return NULL;
	}
	accumulation = read_and_accumulate(fd, accumulation);
	//see if no data been accumulated , or no left data to process
	if (!accumulation || !*accumulation)
	{
		free(accumulation);
		accumulation = NULL;
		return NULL;
	}
	return (extract_line(&accumulation));
}

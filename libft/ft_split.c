/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:15:37 by ycharkou          #+#    #+#             */
/*   Updated: 2024/11/02 09:59:35 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	ft_count_words(char const *s, char sep)
{
	int	i;
	int	words_count;

	words_count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == sep)
			i++;
		if (sep)
		{
			words_count++;
			while (s[i] && s[i] != sep)
				i++;
		}
	}
	return (words_count);
}

static void	*ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static char	*fill_word(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = 0;
	return (word);
}

static void	ft_initiate(size_t *i, int *j, int *is_word, size_t *len, char const *s)
{
	*i = 0;
	*j = 0;
	*is_word = -1;
	*len = ft_strlen(s);
}

char	**ft_split(char const *s, char c)
{
	char	**buffer;
	size_t	i;
	int		j;
	int		is_word;
	size_t	len;

	ft_initiate(&i, &j, &is_word, &len, s);
	buffer = ft_calloc((ft_count_words(s, c) + 1), sizeof(char *));
	if (!buffer)
		return (NULL);
	while (i <= len)
	{
		if (s[i] != c && is_word < 0)
			is_word = i;
		else if ((s[i] == c || i == len) && is_word >= 0)
		{
			buffer[j] = fill_word(s, is_word, i);
			if (!buffer[j])
				return (ft_free(buffer, j));
			is_word = -1;
			j++;
		}
		i++;
	}
	return (buffer);
}

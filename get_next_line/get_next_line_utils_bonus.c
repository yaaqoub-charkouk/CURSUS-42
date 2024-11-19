/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:19:07 by ycharkou          #+#    #+#             */
/*   Updated: 2024/11/19 15:20:13 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *accumulation)
{
	size_t	i;

	i = 0;
	while (accumulation[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *accumulation, char *s2)
{
	char	*string;
	size_t	s_len;
	size_t	s1_len;
	size_t	s2_len;

	if (!s2)
		return (NULL);
	s1_len = 0;
	if (accumulation)
		s1_len = ft_strlen(accumulation);
	s2_len = ft_strlen(s2);
	s_len = s1_len + s2_len;
	string = malloc((s_len + 1) * sizeof(char));
	if (!string)
	{
		free(accumulation);
		return (NULL);
	}
	if (accumulation)
	{
		ft_strlcpy(string, accumulation, s1_len + 1);
		free(accumulation);
	}
	ft_strlcpy(string + s1_len, s2, s2_len + 1);
	return (string);
}

char	*ft_strdup(const char *s1)
{
	char	*string;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s1) + 1;
	string = malloc(len * sizeof(char));
	if (!string)
		return (NULL);
	while (s1[i])
	{
		string[i] = s1[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srcsize;

	srcsize = 0;
	while (src[srcsize] != '\0')
		srcsize++;
	if (dstsize == 0)
		return (srcsize);
	i = 0;
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srcsize);
}

char	*ft_substr(char *accumulation, unsigned int start, size_t len)
{
	size_t	acc_len;
	size_t	final;
	char	*sub;

	if (!accumulation)
		return (NULL);
	acc_len = ft_strlen(accumulation);
	final = acc_len - start;
	if (final > len)
		final = len;
	sub = malloc((final + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, accumulation + start, final + 1);
	return (sub);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 08:07:27 by ycharkou          #+#    #+#             */
/*   Updated: 2024/11/02 13:24:14 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*string;
	size_t			i;

	if (!s)
		return (NULL);
	i = 0;
	string = (unsigned char *)s;
	ch = (unsigned char)c;
	while (i < n)
	{
		if (ch == string[i])
			return ((void *)(string + i));
		i++;
	}
	return (NULL);
}

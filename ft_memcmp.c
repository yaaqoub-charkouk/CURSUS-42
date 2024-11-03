/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 09:12:06 by ycharkou          #+#    #+#             */
/*   Updated: 2024/11/02 13:23:53 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t	n)
{
	const unsigned char	*string1;
	const unsigned char	*string2;
	size_t			i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	string1 = (const unsigned char *)s1;
	string2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (string1[i] != string2[i])
			return (string1[i] - string2[i]);
		i++;
	}
	return (0);
}

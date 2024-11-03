/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:50:14 by ycharkou          #+#    #+#             */
/*   Updated: 2024/10/29 15:59:19 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*source;
	char	*dest;
	size_t			i;

	if (!dst && !src)
		return (dst);
	source = (char *)src;
	dest = (char *)dst;
	i = 0;
	if (dest > source)
	{
		while (len-- > 0)
			dest[len] = source[len];
	}
	else 
	{
		while (len--)
			*dest++ = *source++;
	}
	return (dst);
}

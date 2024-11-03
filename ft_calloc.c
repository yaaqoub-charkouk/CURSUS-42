/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:06:14 by ycharkou          #+#    #+#             */
/*   Updated: 2024/10/29 10:16:01 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*s;
	size_t			size1;

	size1 = count * size;
	s = (unsigned char *)malloc(size1);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, size1);
	return (s);
}

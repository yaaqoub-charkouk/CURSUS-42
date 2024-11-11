/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:14:50 by ycharkou          #+#    #+#             */
/*   Updated: 2024/11/09 19:34:46 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node1;

	node1 = malloc(sizeof(t_list));
	if (!node1)
		return (NULL);
	node1->content = content;
	node1->next = NULL;
	return (node1);
}

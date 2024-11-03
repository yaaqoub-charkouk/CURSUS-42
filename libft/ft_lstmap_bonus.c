/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 07:57:59 by ycharkou          #+#    #+#             */
/*   Updated: 2024/11/02 09:21:38 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	new_list = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if(!new_node)
		{
			del(&new_list);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
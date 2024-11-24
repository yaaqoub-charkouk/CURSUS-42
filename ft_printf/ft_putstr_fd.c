/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:36:10 by ycharkou          #+#    #+#             */
/*   Updated: 2024/11/24 18:11:00 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	bytes_written;

	if (!s)
		return (ft_putstr_fd("(null)", fd));
	i = 0;
	bytes_written = 0;
	while (s[i] != '\0')
	{
		if (write(fd, &s[i], 1) == -1)
			return (-1);
		bytes_written++;
		i++;
	}
	return (bytes_written);
}

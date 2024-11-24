/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:22:22 by ycharkou          #+#    #+#             */
/*   Updated: 2024/11/24 18:29:50 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32 || base[i] == 127)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_putnbr_base_recursive(unsigned long nbr, char *base, int base_len)
{
	int	count;

	count = 0;
	if (nbr >= (unsigned long)base_len)
		count += ft_putnbr_base_recursive(nbr / base_len, base, base_len);
	ft_putchar_fd(base[nbr % base_len], 1);
	count++;
	return (count);
}

int	ft_putnbr_base(unsigned long nbr, char *base)
{
	int				count;
	unsigned long	num;
	int				base_len;

	if (!is_valid_base(base))
		return (0);
	count = 0;
	base_len = ft_strlen(base);
	if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		count++;
		num = -nbr;
	}
	else
		num = nbr;
	count += ft_putnbr_base_recursive(num, base, base_len);
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:56:40 by ycharkou          #+#    #+#             */
/*   Updated: 2024/11/24 18:20:53 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int	    ft_putchar_fd(char c, int fd);
int 	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
int 	ft_putnbr_base(unsigned long n, char *base);

#endif
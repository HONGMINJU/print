/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhong <mhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:27:56 by mhong             #+#    #+#             */
/*   Updated: 2022/02/06 21:22:24 by mhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check(const char *str, va_list argList)
{
	if (*str == 's')
		return (print_s(va_arg(argList, char *)));
	else if (*str == 'p')
		return (print_p(va_arg(argList, long long)));
	else if (*str == 'd' || *str == 'i')
		return (print_di(va_arg(argList, int)));
	else if (*str == 'x')
		return (print_xX(va_arg(argList, unsigned int), 0));
	else if (*str == 'X')
		return (print_xX(va_arg(argList, unsigned int), 1));
	else if (*str == 'u')
		return (print_u(va_arg(argList, unsigned int)));
	else if (*str == 'c')
		ft_putchar_fd(va_arg(argList, char), 1);
	else if (*str == '%')
		ft_putchar_fd('%', 1);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list			argList;
	unsigned int	cnt;

	va_start(argList, str);
	cnt = 0;
	while (*str != '\0')
	{
		if (*str != '%' && cnt++)
			ft_putchar_fd(*str++, 1);
		else
			cnt += check(str++, argList);
	}
	return (cnt);
}
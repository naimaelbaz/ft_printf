/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 09:38:58 by nel-baz           #+#    #+#             */
/*   Updated: 2022/11/07 21:56:26 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(va_list args, char ptr)
{
	int		index;

	index = 0;
	if (ptr == 'd' || ptr == 'i')
		index += ft_putnbr(va_arg(args, int));
	else if (ptr == 'c')
		index += ft_putchar(va_arg(args, int));
	else if (ptr == 's')
		index += ft_putstr(va_arg(args, char *));
	else if (ptr == 'x')
		index += ft_putnbrhex(va_arg(args, unsigned int), \
		"0123456789abcdef", 16);
	else if (ptr == 'X')
		index += ft_putnbrhex(va_arg(args, unsigned int), \
		"0123456789ABCDEF", 16);
	else if (ptr == 'u')
		index += ft_putnbrhex(va_arg(args, unsigned int), "0123456789", 10);
	else if (ptr == 'p')
		index += ft_putpointer(va_arg(args, void *));
	else if (ptr == '%')
		index += ft_putchar(ptr);
	else
		ft_putchar(ptr);
	return (index);
}

int	ft_printf(const char *ptr, ...)
{
	va_list	args;
	int		index;
	int		i;

	i = 0;
	index = 0;
	va_start(args, ptr);
	while (ptr[i])
	{
		if (ptr[i] && ptr[i] == '%')
			index += ft_check(args, ptr[++i]);
		else
			index += ft_putchar(ptr[i]);
		i++;
	}
	va_end(args);
	return (index);
}

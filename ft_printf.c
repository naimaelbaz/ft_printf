/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 09:38:58 by nel-baz           #+#    #+#             */
/*   Updated: 2022/11/07 14:04:57 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(va_list args, char ptr)
{
	char	*str;
	int		index;

	index = 0;
	if (ptr == 'd' || (ptr + 1) == 'i')
		index += ft_putnbr(va_arg(args, int));
	else if (ptr == 'c')
		index += ft_putchar(va_arg(args, int));
	else if (ptr == 's')
		index += ft_putstr(va_arg(args, char *));
	else if (ptr == 'x')
		index += ft_putnbrhex(va_arg(args, unsigned int), "0123456789abcdef", 16);
	else if (ptr == 'X')
		index += ft_putnbrhex(va_arg(args, unsigned int), "0123456789ABCDEF", 16);
	else if (ptr == 'u')
		index += ft_putnbrhex(va_arg(args, unsigned int),"0123456789", 10);
	else if (ptr == 'p')
		index += ft_putnbrhex(va_arg(args, unsigned long));
	//else if (*(ptr + 1) == '%')
		//ft_print(va_arg(args, int));
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
	return (index);
}

int main()
{
	 void *p;
    ft_printf("%p",&p);
}
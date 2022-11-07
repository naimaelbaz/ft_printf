/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 09:38:58 by nel-baz           #+#    #+#             */
/*   Updated: 2022/11/07 01:35:12 by nel-baz          ###   ########.fr       */
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
		index += ft_putnbrhex(va_arg(args, unsigned int), "0123456789abcdef");
	else if (ptr == 'X')
		index += ft_putnbrhex(va_arg(args, unsigned int), "0123456789ABCDEF");
	//else if (*(ptr + 1) == 'u')
	//	index += ft_print(va_arg(args, unsigned int), str, 10);
	//else if (*(ptr + 1) == 'p')
		//ft_print(va_arg(args, int));
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
/*int main()
{
	printf("%d",ft_printf("%s\n", NULL));
}*/
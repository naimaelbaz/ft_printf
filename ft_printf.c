/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 09:38:58 by nel-baz           #+#    #+#             */
/*   Updated: 2022/11/06 16:53:09 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	ft_check(va_list args, const char index)
{
	char	*str;

	if (index == 'd')
		str == ft_itoa(va_arg(args, int));
	else if (index == 'c')
		index == va_arg(args, char);
	else if (index == 's')
		ft_rev(va_arg(args, char *));
	else if (index == 'x')
		ft_print(va_arg(args, int), str, 16);
	else if (index == 'X')
		ft_print(va_arg(args, int), str, 16);
	else if (index == 'i')
		ft_print(va_arg(args, int), str, 10);
	else if (index == 'u')
		ft_print(va_arg(args, unsigned int), str, 10);
	else if (index == 'p')
		ft_print(va_arg(args, int));
	else if (index == '%')
		ft_print(va_arg(args, int));
}

int	ft_printf(const char *ptr, ...)
{
	va_list	args;
	char	*tmp;
	size_t	i;
	size_t	len;
	char	*buffer;

	i = 0;
	len = ft_strlen(ptr);
	buffer = malloc(sizeof(char) * (len + 1));
	if (!buffer)
		return (NULL);
	va_start(args, ptr);
	while (ptr[i] && i < len)
	{
		if (ptr[i] && ptr[i] == '%')
			tmp = ft_check(args, ptr + i);
			ft_memcpy(&buffer[i],tmp,ft_strlen(tmp));
		else
			buffer[i] = ptr[i];
		i++;
	}
	ft_putstr_fd(buffer, 1);
	return (i);
}

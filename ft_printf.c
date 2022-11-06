/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 09:38:58 by nel-baz           #+#    #+#             */
/*   Updated: 2022/11/06 11:00:13 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_check(va_list args, const char *ptr)
{
	char *str;
	if (*(ptr + 1) == 'd')
		ft_rev(va_arg(args, int), str, 10);
	else if (*(ptr + 1) == 'c')
		ft_rev(va_arg(args, char), str);
	//if (*(ptr + 1) == 's')
		//ft_rev(i);
	if (*(ptr + 1) == 'x')
		ft_print(va_arg(args, int), str, 16);
	if (*(ptr + 1) == 'X')
		ft_print(va_arg(args, int), str, 16);
	if (*(ptr + 1) == 'i')
		ft_print(va_arg(args, int), str, 10);
	if (*(ptr + 1) == 'u')
		ft_print(va_arg(args, int), str, 10);
	if (*(ptr + 1) == 'p')
		ft_print(va_arg(args, int));
	if (*(ptr + 1) == '%')
		ft_print(va_arg(args, int));
}

int	ft_printf(const char *ptr, ...)
{
	va_list	args;
	int		len;
	int		i;
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
			ft_check(args, ptr + i);
		else
			buffer[i] = ptr[i];
		i++;
	}
}

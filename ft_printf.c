/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 09:38:58 by nel-baz           #+#    #+#             */
/*   Updated: 2022/11/06 09:12:02 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_check(const char *ptr, char buffer)
{
	if (*(ptr + 1) == 'd')
		ft_atoi()
	if (*(ptr + 1) == 'c')

	if (*(ptr + 1) == 's')
	
	if (*(ptr + 1) == 'x')
	
	if (*(ptr + 1) == 'X')
		
}

int	ft_printf(const char *ptr, ...)
{
	va_list	args;
	int		len;
	int		i;
	char	*buffer;

	i = 0;
	len = ft_strlen(ptr);
	buffer = malloc(sizeof(char) * (len +1));
	if (!buffer)
		return (NULL);
	va_start(args, ptr);
	while (ptr[i] && i < len)
	{
		if (ptr[i] && ptr[i] == '%')
			ft_check(ptr + i, buffer + i);
		else
			buffer[i] = ptr[i];
		i++;
	}
}

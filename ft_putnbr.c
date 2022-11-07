/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 22:40:31 by nel-baz           #+#    #+#             */
/*   Updated: 2022/11/07 17:00:20 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_size(int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*ft_itoa(int n)
{
	int		ln;
	char	*ptr;

	if (n == -2147483648)
		return ("-2147483648");
	ln = count_size(n);
	ptr = (char *)malloc(sizeof(char) * (ln + 1));
	if (!ptr)
		return (NULL);
	ptr[ln--] = '\0';
	if (n == 0)
		ptr[0] = '0';
	while (n)
	{
		if (n < 0)
		{
			n *= -1;
			ptr[0] = '-';
		}
		ptr[ln] = (n % 10) + 48;
		n /= 10;
		ln--;
	}
	return (ptr);
}

int	ft_putnbr(int n)
{
	char	*str;
	int		len;

	str = ft_itoa(n);
	len = ft_putstr(str);
	free(str);
	str = NULL;
	return (len);
}

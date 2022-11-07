/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 00:50:04 by nel-baz           #+#    #+#             */
/*   Updated: 2022/11/07 11:36:49 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_size(unsigned int n, int b)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n != 0)
	{
		n /= b;
		count++;
	}
	return (count);
}

static char	*ft_itoabase(unsigned int n, char *base, int b)
{
	int		ln;
	char	*ptr;

	ln = count_size(n, b);
	ptr = (char *)malloc(sizeof(char) * (ln + 1));
	if (!ptr)
		return (NULL);
	ptr[ln--] = '\0';
	if (n == 0)
		ptr[0] = '0';
	while (n)
	{
		ptr[ln] = base[n % b];
		n /= b;
		ln--;
	}
	return (ptr);
}

int	ft_putnbrhex(unsigned int index, char *base, int b)
{
	char	*str;
	int		len;

	str = ft_itoabase(index, base, b);
	len = ft_putstr(str);
	free(str);
	str = NULL;
	return (len);
}

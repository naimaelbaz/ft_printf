/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 00:50:04 by nel-baz           #+#    #+#             */
/*   Updated: 2022/11/07 02:25:20 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_size(int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n != 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}

static char	*ft_itoabase(int n, char *base)
{
	int		ln;
	char	*ptr;

	ln = count_size(n);
	ptr = (char *)malloc(sizeof(char) * (ln + 1));
	if (!ptr)
		return (NULL);
	ptr[ln--] = '\0';
	if (n == 0)
		ptr[0] = '0';
	while (n)
	{
		ptr[ln] = base[n % 16];
		n /= 16;
		ln--;
	}
	return (ptr);
}

int	ft_putnbrhex(int index, char *base)
{
	char	*str;
	int		len;

	str = ft_itoabase(index, base);
	len = ft_putstr(str);
	free(str);
	str = NULL;
	return (len);
}

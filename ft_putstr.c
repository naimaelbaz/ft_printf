/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:55:50 by nel-baz           #+#    #+#             */
/*   Updated: 2022/11/07 01:37:09 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;

	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (s && s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}
//  int main()
//  {
// 	printf("%d", ft_putstr(NULL));
// 		//ft_putstr(NULL));
//  }
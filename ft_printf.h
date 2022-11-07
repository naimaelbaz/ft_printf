/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 09:35:48 by nel-baz           #+#    #+#             */
/*   Updated: 2022/11/07 11:37:33 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *ptr, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int index);
int		ft_putnbrhex(unsigned int index, char *base, int b);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemkliuiev <artemkliuiev@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 22:24:55 by artemkliuie       #+#    #+#             */
/*   Updated: 2024/07/15 23:45:59 by artemkliuie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexlen(unsigned	long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	puthex(unsigned long num, const char format)
{
	if (num >= 16)
	{
		puthex(num / 16, format);
		puthex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			printchar(num + '0');
		else
		{
			if (format == 'x')
				printchar(num - 10 + 'a');
			if (format == 'X')
				printchar(num - 10 + 'A');
		}
	}
}

int	printhex(unsigned long num, const char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		puthex(num, format);
	return (hexlen(num));
}

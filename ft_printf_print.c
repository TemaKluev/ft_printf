/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemkliuiev <artemkliuiev@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 19:02:36 by artemkliuie       #+#    #+#             */
/*   Updated: 2024/07/15 23:50:44 by artemkliuie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	printstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (printstr("(null)"));
	while (s[i] != '\0')
	{
		printchar(s[i]);
		i++;
	}
	return (i);
}

int	printnum(int num)
{
	int		len;
	char	*str;

	len = 0;
	str = ft_itoa(num);
	len = printstr(str);
	free (str);
	return (len);
}

int	printunum(unsigned int n)
{
	int	i;

	i = 0;
	if (n / 10)
		i += printunum(n / 10);
	i += printchar((n % 10) + '0');
	return (i);
}

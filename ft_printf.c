/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemkliuiev <artemkliuiev@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 20:29:02 by akliuiev          #+#    #+#             */
/*   Updated: 2024/07/15 23:42:47 by artemkliuie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printptr(void *ptr)
{
	int	i;

	i = 0;
	if (ptr == 0)
		return (printstr("(nil)"));
	i += printstr("0x");
	i += printhex((size_t)ptr, 'x');
	return (i);
}

int	make_flags(const char s, va_list args)
{
	int	len;

	len = 0;
	if (s == 'c')
		len += printchar(va_arg(args, int));
	else if (s == 's')
		len += printstr(va_arg(args, char *));
	else if (s == 'd' || s == 'i')
		len += printnum(va_arg(args, int));
	else if (s == 'u')
		len += printunum(va_arg(args, unsigned int));
	else if (s == 'x' || s == 'X')
		len += printhex(va_arg(args, unsigned int), s);
	else if (s == 'p')
		len += printptr(va_arg(args, void *));
	else if (s == '%')
		len += printchar('%');
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start (args, s);
	while (s[i] != '\0')
	{
		if (s[i] != '%')
		{
			printchar(s[i]);
			len++;
		}
		else
		{
			i++;
			len += make_flags(s[i], args);
		}
		i++;
	}
	va_end (args);
	return (len);
}

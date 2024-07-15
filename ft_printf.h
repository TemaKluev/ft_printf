/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemkliuiev <artemkliuiev@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 19:02:18 by artemkliuie       #+#    #+#             */
/*   Updated: 2024/07/15 23:46:17 by artemkliuie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	printchar(char c);
int	printstr(char *s);
int	printnum(int num);
int	printunum(unsigned int n);
int	printhex(unsigned long num, const char format);

#endif
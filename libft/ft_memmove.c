/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemkliuiev <artemkliuiev@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 22:03:57 by akliuiev          #+#    #+#             */
/*   Updated: 2024/07/15 23:32:11 by artemkliuie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	i = n;
	d = (char *)dest;
	s = (char *)src;
	if (dest == NULL && src == NULL)
		return (dest);
	if (dest == src)
		return (dest);
	if (dest > src)
		while (i--)
			d[i] = s[i];
	else
		while (i--)
			*d++ = *s++;
	return (dest);
}

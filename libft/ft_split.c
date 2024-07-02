/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akliuiev <akliuiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:43:12 by akliuiev          #+#    #+#             */
/*   Updated: 2024/06/25 23:46:48 by akliuiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	words_count(const char *s, int c)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			num++;
			while (s[i] != c && (s[i] != '\0'))
				i++;
		}
		else if (s[i] == c)
			i++;
	}
	return (num);
}

int	word_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

void	free_all(char **str, int i)
{
	while (i >= 0)
	{
		free (str[i]);
		i--;
	}
	free (str);
}

char	**ft_div(const char *s, char c, char **str, int num)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < num)
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		str[j] = ft_substr(s, i, word_len(&s[i], c));
		if (str[j] == NULL)
		{
			free_all(str, j);
			return (NULL);
		}
		while (s[i] != '\0' && s[i] != c)
			i++;
		j++;
	}
	str[j] = NULL;
	return (str);
}

char	**ft_split(const char *s, char c)
{
	int		num;
	char	**str;

	if (s == NULL)
		return (NULL);
	num = words_count(s, c);
	str = malloc (sizeof(char *) * (num + 1));
	if (str == NULL)
		return (NULL);
	str = ft_div(s, c, str, num);
	return (str);
}

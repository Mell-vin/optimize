/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgumede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 09:50:04 by lgumede           #+#    #+#             */
/*   Updated: 2019/08/29 14:49:52 by lgumede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_word(const char *s, char c)
{
	int			i;
	int			len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static int		counter(const char *s, char c)
{
	int			i;
	int			count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**str;
	int			i;
	int			j;
	int			k;

	if (!s)
		return (NULL);
	str = (char **)malloc((sizeof(*str) * counter(s, c)) + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = -1;
	while (++j < counter(s, c))
	{
		k = 0;
		if (!(str[j] = (char *)malloc(sizeof(char) * ft_word(&s[i], c) + 1)))
			str[j] = NULL;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
			str[j][k++] = s[i++];
		str[j][k] = '\0';
	}
	str[j] = NULL;
	return (str);
}

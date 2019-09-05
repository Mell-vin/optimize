/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgumede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 09:50:39 by lgumede           #+#    #+#             */
/*   Updated: 2019/07/19 09:50:41 by lgumede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(const char *s)
{
	int		i;
	int		k;
	int		j;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	while (j >= 0 && (s[j] == ' ' || s[j] == '\t' || s[j] == '\n'))
		j--;
	if (j < i)
		j = i - 1;
	if (!(str = (char*)malloc(sizeof(char) * (j - i + 2))))
		return (NULL);
	k = 0;
	while (i <= j)
	{
		str[k++] = s[i++];
	}
	str[k] = '\0';
	return (str);
}

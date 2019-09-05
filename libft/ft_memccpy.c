/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgumede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 09:41:54 by lgumede           #+#    #+#             */
/*   Updated: 2019/07/19 09:41:55 by lgumede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*str1;
	char	*str2;
	char	a;
	size_t	i;

	str1 = (char *)dest;
	str2 = (char *)src;
	a = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		str1[i] = str2[i];
		if (str2[i] == a)
		{
			return (&str1[i + 1]);
		}
		i++;
	}
	return (0);
}

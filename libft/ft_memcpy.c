/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgumede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 09:42:26 by lgumede           #+#    #+#             */
/*   Updated: 2019/07/19 09:42:28 by lgumede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*str1;
	char	*str2;
	size_t	i;

	str1 = (char*)dest;
	str2 = (char*)src;
	i = 0;
	if (!str1 && str2 == NULL)
		return (NULL);
	while (i < n)
	{
		str1[i] = str2[i];
		i++;
	}
	return (str1);
}

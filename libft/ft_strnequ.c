/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgumede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 09:47:03 by lgumede           #+#    #+#             */
/*   Updated: 2019/07/19 09:49:15 by lgumede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;
	int		len;

	i = 0;
	len = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while ((s1[i] != '\0' || s2[i] != '\0') && (i < n))
	{
		len = ((char)s1[i] - (char)s2[i]);
		if (len != 0)
			return (0);
		i++;
	}
	if (len == 0)
		return (1);
	return (1);
}

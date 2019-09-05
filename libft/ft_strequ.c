/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgumede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 09:46:46 by lgumede           #+#    #+#             */
/*   Updated: 2019/07/19 09:46:48 by lgumede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int	i;

	i = 0;
	if (s1 && s2)
	{
		if (s1 == NULL && s2 == NULL)
			return (0);
		if (ft_strlen(s1) != ft_strlen(s2))
			return (0);
		while (s1[i] && s2[i])
			if (s1[i] != s2[i])
			{
				i++;
				return (0);
			}
			else if (s1[i] == s2[i])
				i++;
		return (1);
	}
	return (0);
}

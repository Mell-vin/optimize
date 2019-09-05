/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgumede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 09:41:40 by lgumede           #+#    #+#             */
/*   Updated: 2019/07/19 09:41:42 by lgumede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	char	*ptr;

	if (!(ptr = (char *)malloc(size * sizeof(size_t))))
		return (NULL);
	ft_bzero(ptr, size);
	return (ptr);
}

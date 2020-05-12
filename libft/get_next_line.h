/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgumede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 09:37:10 by lgumede           #+#    #+#             */
/*   Updated: 2019/07/19 12:37:51 by lgumede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1

# include <fcntl.h>
# include "unistd.h"
# include "stdlib.h"
# include <sys/types.h>
# include <sys/uio.h>
# include "libft.h"

int			get_next_line(const int fd, char **line);

#endif

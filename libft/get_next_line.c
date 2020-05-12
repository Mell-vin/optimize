/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgumede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 09:36:51 by lgumede           #+#    #+#             */
/*   Updated: 2019/07/19 12:36:09 by lgumede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_len(char *s, char c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (0);
}

static int	ft_readline(char **str, char **line)
{
	char *temp;

	if (ft_strchr(*str, '\n'))
	{
		*line = ft_strsub(*str, 0, ft_len(*str, '\n'));
		temp = ft_strdup(ft_strchr(*str, '\n') + 1);
		ft_strdel(str);
		*str = temp;
	}
	else
	{
		*line = ft_strdup(*str);
		ft_strdel(str);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*str[1024];
	char		buff[BUFF_SIZE + 1];
	int			bytes;
	char		*temp;

	if (fd < 0 || line == NULL || read(fd, buff, 0) < 0)
		return (-1);
	if (str[fd] == NULL)
		str[fd] = ft_strnew(1);
	bytes = 0;
	while (!ft_strchr(str[fd], '\n') && (bytes = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[bytes] = '\0';
		temp = ft_strjoin(str[fd], buff);
		ft_strdel(&str[fd]);
		str[fd] = temp;
	}
	if (bytes < 0)
		return (-1);
	else if (bytes == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
		return (0);
	else
		return (ft_readline(&str[fd], line));
}

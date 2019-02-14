/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:08:09 by aschoenh          #+#    #+#             */
/*   Updated: 2018/12/07 13:29:38 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

size_t			ft_strlen_eol(char *s)
{
	size_t			i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	return (i);
}

char			*ft_strndup(char *src, size_t len)
{
	char			*dest;
	size_t			i;

	if (!(dest = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = -1;
	while (++i < len)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

static int		ft_fill_line(char **file, char **line, int fd)
{
	char			*tmp;
	char			*ptr;

	ptr = ft_strchr(file[fd], '\n');
	if (ptr)
	{
		*line = ft_strndup(file[fd], ft_strlen_eol(file[fd]));
		if (!(tmp = ft_strdup(++ptr)))
			return (-1);
		free(file[fd]);
		file[fd] = tmp;
		if (!(file[fd][0]))
			ft_strdel(&(file[fd]));
	}
	else
	{
		if (!(*line = ft_strdup(file[fd])))
			return (-1);
		ft_strdel(&file[fd]);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char		*file[MAX_FD];
	char			buf[BUFF_SIZE + 1];
	char			*stock;
	int				ret;

	if (fd < 0 || fd > MAX_FD || read(fd, buf, 0) < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret < 0)
			return (-1);
		buf[ret] = '\0';
		if (!(file[fd]))
			file[fd] = ft_strnew(1);
		if (!(stock = ft_strjoin(file[fd], buf)))
			return (-1);
		free(file[fd]);
		file[fd] = stock;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (!(file[fd]) || ft_strlen(file[fd]) == 0)
		return (0);
	return (ft_fill_line(file, line, fd));
}

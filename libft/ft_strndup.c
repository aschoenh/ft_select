/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 12:03:59 by aschoenh          #+#    #+#             */
/*   Updated: 2019/02/19 14:23:19 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *s1, size_t n)
{
	int		len;
	char	*dst;

	len = ft_strlen(s1);
	len > (int)n ? (int)n : len ;
	if (!(dst = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	dst[len] = '\0';
	while (len > 0)
	{
		--len;
		dst[len] = s1[len];
	}
	return (dst);
}

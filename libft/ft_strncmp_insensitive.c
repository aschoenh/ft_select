/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 12:00:07 by aschoenh          #+#    #+#             */
/*   Updated: 2019/02/21 19:02:27 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp_insensitive(const char *string1, const char *string2, size_t n)
{
	int		i;
	char	*s1;
	char	*s2;

	s1 = ft_strdup(string1);
	s2 = ft_strdup(string2);
	s1 = ft_tolower(s1);
	s2 = ft_tolower(s2);
	if (!n)
		return (0);
	i = 0;
	while (*(s1 + i) && (*(s1 + i) == *(s2 + i)) && i + 1 < (int)n)
		i++;
	return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
}

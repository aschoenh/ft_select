/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:47:12 by aschoenh          #+#    #+#             */
/*   Updated: 2019/02/18 18:28:06 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_tolower(char *str)
{
	int	i;

	i = 0;
	if ((str[i]) >= 'A' && str[i] <= 'Z')
		str[i] -= 'A' + 'a';
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:38:41 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/01/17 11:19:37 by dfiliagg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char	*d;
	char	*s;
	size_t	i;
	size_t	sl;

	d = (char *)dst;
	s = (char *)src;
	i = 0;
	sl = ft_strlen(s);
	if (!d || !s || size == 0)
		return (sl);
	while (i < size - 1 && s[i] != 0)
	{
		d[i] = s[i];
		i++;
	}
		d[i] = 0;
	return (sl);
}

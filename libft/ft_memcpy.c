/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:59:16 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/01/20 10:43:42 by dfiliagg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*s;
	char	*s2;

	if (!dest && !src)
		return (0);
	s = (char *)dest;
	s2 = (char *)src;
	i = 0;
	while (i < n)
	{
		s[i] = s2[i];
		i++;
	}
	return (dest);
}

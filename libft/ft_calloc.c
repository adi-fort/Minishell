/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 08:04:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/01/23 13:57:44 by dfiliagg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*temp;
	size_t	bytes;

	if (count == 0 || size == 0)
		return (ft_calloc(1, 1));
	bytes = count * size;
	if (bytes / size != count)
		return (0);
	temp = (void *)malloc(count * size);
	if (temp == 0)
		return (0);
	ft_bzero(temp, count * size);
	return ((void *)temp);
}

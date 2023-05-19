/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 07:49:41 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/01/20 15:02:31 by dfiliagg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <stdlib.h>

int	allocatec(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n > 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

void	writec(char *c, int n)
{
	int	i;

	i = allocatec(n);
	if (n < 0)
	{
		c[0] = '-';
		n *= -1;
	}
	c[i] = 0;
	i--;
	while (n > 0)
	{
		c[i] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	char	*c;

	if (n == -2147483648)
	{
		c = malloc(12);
		if (!c)
			return (0);
		ft_strlcpy(c, "-2147483648", 12);
		return (c);
	}
	if (n == 0)
	{
		c = malloc(2);
		if (!c)
			return (0);
		c[0] = '0';
		c[1] = 0;
		return (c);
	}
	c = malloc(allocatec(n) + 1);
	if (!c)
		return (0);
	writec(c, n);
	return (c);
}

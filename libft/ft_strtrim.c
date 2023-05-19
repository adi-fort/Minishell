/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:10:57 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/01/23 08:09:48 by dfiliagg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*end(char *outstr, char *outstr_start, unsigned int outstr_size)
{
	outstr = malloc(sizeof(char) * outstr_size);
	if (!outstr)
		return (0);
	ft_strlcpy(outstr, outstr_start, outstr_size);
	return (outstr);
}

static unsigned int	is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int				i;
	unsigned int	outstr_size;
	char			*outstr_start;
	char			*outstr_end;
	char			*outstr;

	if (!s1 || !set)
		return (0);
	i = 0;
	while (s1[i] && is_in_set(s1[i], set))
		i++;
	outstr_start = (char *)&s1[i];
	i = ft_strlen((char *)s1) - 1;
	if (i != -1)
		while (i >= 0 && is_in_set(s1[i], set))
			i--;
	outstr_end = (char *)&s1[i];
	if (!*s1 || outstr_end == outstr_start)
		outstr_size = 2;
	else
		outstr_size = outstr_end - outstr_start + 2;
	outstr = 0;
	return (end(outstr, outstr_start, outstr_size));
}

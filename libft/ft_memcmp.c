/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:20:04 by mhernang          #+#    #+#             */
/*   Updated: 2023/01/22 17:02:08 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*g;
	unsigned char	*p;
	size_t			i;

	i = 0;
	g = (unsigned char *) str1;
	p = (unsigned char *) str2;
	while (i < n)
	{
		if (g[i] != p[i])
			return (g[i] - p[i]);
		i++;
	}
	return (0);
}

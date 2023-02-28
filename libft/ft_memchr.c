/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:54:47 by mhernang          #+#    #+#             */
/*   Updated: 2023/01/29 21:10:47 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	char	*g;
	size_t	i;

	i = 0;
	g = (char *)str;
	while (i < n)
	{
		if (g[i] == (char)c)
			return (&g[i]);
		i++;
	}
	return (NULL);
}

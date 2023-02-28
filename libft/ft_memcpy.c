/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:48:33 by mhernang          #+#    #+#             */
/*   Updated: 2023/02/05 20:08:52 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*g;
	unsigned char	*p;
	size_t			i;

	i = 0;
	if ((dest == NULL && src == NULL) || !n)
		return (dest);
	g = (unsigned char *) src;
	p = (unsigned char *) dest;
	if (g[0] == 0 && p[0] == 0)
		return (p);
	while (i < n)
	{
		p[i] = g[i];
		i++;
	}
	return (p);
}

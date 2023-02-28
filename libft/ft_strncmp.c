/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:48:06 by mhernang          #+#    #+#             */
/*   Updated: 2023/01/23 16:10:40 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	*g;

	i = 0;
	p = (unsigned char *) s1;
	g = (unsigned char *) s2;
	while ((p[i] != '\0' || g[i] != '\0') && i < n)
	{
		if (p[i] != g[i])
			return (p[i] - g[i]);
		i++;
	}
	return (0);
}

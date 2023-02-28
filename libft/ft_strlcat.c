/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:11:49 by mhernang          #+#    #+#             */
/*   Updated: 2023/02/07 11:06:46 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_strlen_max(char *dest, unsigned int size)
{
	int	i;

	i = 0;
	while (dest[i] && size > 0)
	{
		i++;
		size--;
	}
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	leng_dest;
	size_t	leng_source;

	if ((!dest || !src) && !size)
		return (0);
	i = ft_strlen_max(dest, size);
	j = 0;
	leng_dest = ft_strlen_max(dest, size);
	leng_source = ft_strlen(src);
	if (size < 1)
		return (leng_source + size);
	while (src[j] != '\0' && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (i < size)
		dest[i] = '\0';
	if (size < leng_dest)
		return (leng_source + size);
	else
		return (leng_dest + leng_source);
}

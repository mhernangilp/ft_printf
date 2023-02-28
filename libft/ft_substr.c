/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:54:55 by mhernang          #+#    #+#             */
/*   Updated: 2023/02/05 21:32:08 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_optimal_len(char const *s, unsigned int start, size_t len)
{
	size_t	len_str;

	len_str = ft_strlen(&s[start]);
	if (len < len_str)
		return (len);
	return (len_str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*t;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		t = malloc(1);
		if (!t)
			return (NULL);
		t[0] = 0;
		return (t);
	}
	t = malloc ((get_optimal_len(s, start, len) * sizeof(char)) + 1);
	if (!t)
		return (NULL);
	while (s[start] && len > 0)
	{
		t[i++] = s[start];
		len--;
		start++;
	}
	t[i] = '\0';
	return ((char *) t);
}

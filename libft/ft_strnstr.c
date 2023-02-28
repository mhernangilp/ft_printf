/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:39:01 by mhernang          #+#    #+#             */
/*   Updated: 2023/01/29 22:03:14 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	loop(size_t *temp, size_t *j)
{
	*temp += 1;
	*j += 1;
}

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	temp;

	i = 0;
	if ((!big || !little) && !len)
		return (NULL);
	if (little[i] == '\0')
		return ((char *) big);
	while (big[i])
	{
		j = 0;
		if (big[i] == little[j])
		{
			temp = i;
			while (big[temp] == little[j] && little[j] && i < len)
				loop (&temp, &j);
			if (temp > len)
				return (NULL);
			if (little[j] == '\0' && i < len)
				return ((char *) &big[i]);
		}
		i++;
	}
	return (NULL);
}

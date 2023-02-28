/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:16:48 by mhernang          #+#    #+#             */
/*   Updated: 2023/01/27 18:22:07 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void	sum(int *i, int *j)
{
	*i += 1;
	*j += 1;
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*t;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	t = malloc(ft_strlen((char *) s1) + ft_strlen((char *) s2) + 1);
	if (!t)
		return (NULL);
	while (s1[j])
	{
		t[i] = s1[j];
		sum(&i, &j);
	}
	j = 0;
	while (s2[j])
	{
		t[i] = s2[j];
		sum(&i, &j);
	}
	t[i] = '\0';
	return (t);
}

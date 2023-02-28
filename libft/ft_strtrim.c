/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:01:41 by mhernang          #+#    #+#             */
/*   Updated: 2023/02/05 20:21:10 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getstart(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	while (s1[i])
	{
		j = 0;
		found = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				found = 1;
			j++;
		}
		if (found == 0)
			return (i);
		i++;
	}
	return (i);
}

static int	getend(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	found;

	i = ft_strlen(s1)-1;
	while (i >= 0)
	{
		j = 0;
		found = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				found = 1;
			j++;
		}
		if (found == 0)
			return (i + 1);
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	int		start;
	int		end;

	if (!s1)
		return (NULL);
	start = getstart(s1, set);
	end = getend(s1, set);
	if (start > end)
	{
		p = malloc(1);
		*p = '\0';
		return (p);
	}
	p = malloc((end - start) * sizeof(char) + 1);
	if (!p)
		return (NULL);
	if ((size_t) start == ft_strlen(s1))
		return (p);
	ft_strlcpy(p, &s1[start], end - start + 1);
	return (p);
}

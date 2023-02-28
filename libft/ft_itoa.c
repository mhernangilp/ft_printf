/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:15:44 by mhernang          #+#    #+#             */
/*   Updated: 2023/01/23 16:08:48 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_getintlen(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	if (n == 0)
		return (1);
	while (n / 1 != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	ft_nullandneg(int *i, int *n, char *p)
{
	p[*i] = '\0';
	*i -= 1;
	if (*n < 0)
	{
		p[0] = '-';
		*n *= -1;
	}
}

static void	ft_ismin(char *p, int i)
{
	unsigned int	n;

	n = 2147483648;
	while (n / 1 != 0)
	{
		p[i] = n % 10 + 48;
		i--;
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*p;
	int		i;

	i = ft_getintlen(n);
	p = malloc(sizeof(char) * ft_getintlen(n) + 1);
	if (!p)
		return (NULL);
	ft_nullandneg(&i, &n, p);
	if (n == -2147483648)
	{
		ft_ismin(p, i);
		return (p);
	}
	if (n == 0)
		p[i] = '0';
	while (n / 1 != 0)
	{
		p[i] = n % 10 + 48;
		i--;
		n /= 10;
	}
	return (p);
}

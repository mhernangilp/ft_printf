/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:54:36 by mhernang          #+#    #+#             */
/*   Updated: 2023/02/07 11:38:49 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit(const char *str, int i)
{
	if ((str[i] >= '0') && (str[i] <= '9'))
		return (1);
	else
		return (0);
}

static int	espacios(int c)
{
	if (c == ' ')
		return (1);
	else if (c == '\n')
		return (1);
	else if (c == '\t')
		return (1);
	else if (c == '\r')
		return (1);
	else if (c == '\v')
		return (1);
	else if (c == '\f')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	value;

	i = 0;
	sign = 0;
	value = 0;
	while (espacios(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign++;
		i++;
	}
	while (digit(str, i))
	{
		value = value * 10 + (str[i] - '0');
		i++;
	}
	if ((sign % 2) == 1)
		value *= -1;
	return (value);
}

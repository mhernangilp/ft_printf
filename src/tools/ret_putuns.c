/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_putuns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:39:34 by mhernang          #+#    #+#             */
/*   Updated: 2023/03/21 14:55:24 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static	int	getlen(unsigned int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_uitoa(unsigned int n)
{
	char	*str;
	int		len;

	len = getlen(n);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	str[len] = '\0';
	while (n)
	{
		str[--len] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}

int	ret_putuns(unsigned int n)
{
	char	*str;
	int		ret;

	if (!n)
		ret = ret_putchar('0');
	else
	{
		str = ft_uitoa(n);
		ret = ret_putstr(str);
		free(str);
	}
	return (ret);
}

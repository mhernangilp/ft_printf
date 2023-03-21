/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_puthex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:03:17 by mhernang          #+#    #+#             */
/*   Updated: 2023/03/21 15:14:38 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static int	gethexlen(unsigned int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i);
}

static void	puthex_rec(unsigned int n, const char mode)
{
	if (n > 15)
	{
		puthex_rec(n / 16, mode);
		puthex_rec(n % 16, mode);
	}
	else
	{
		if (n < 10)
			ret_putchar(n + '0');
		else
		{
			if (mode == 'x')
				ret_putchar(n + 'a' - 10);
			else
				ret_putchar(n + 'A' - 10);
		}
	}
}

int	ret_puthex(unsigned int n, const char mode)
{
	int	ret;

	if (!n)
		ret = ret_putchar('0');
	else
	{
		puthex_rec(n, mode);
		ret = gethexlen(n);
	}
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_putvoid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:17:51 by mhernang          #+#    #+#             */
/*   Updated: 2023/03/21 15:13:16 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static int	getlen(uintptr_t n)
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

static void	putptr_rec(uintptr_t n)
{
	if (n >= 16)
	{
		putptr_rec(n / 16);
		putptr_rec(n % 16);
	}
	else
	{
		if (n < 10)
			ret_putchar(n + '0');
		else
			ret_putchar(n + 'a' - 10);
	}
}

int	ret_putvoid(unsigned long long ptr)
{
	int		ret;

	ret = ret_putstr("0x");
	if (!ptr)
		ret += ret_putchar('0');
	else
	{
		putptr_rec(ptr);
		ret += getlen(ptr);
	}
	return (ret);
}

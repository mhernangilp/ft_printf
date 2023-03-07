/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_putnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:06:25 by mhernang          #+#    #+#             */
/*   Updated: 2023/03/07 20:06:47 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	ret_putnbr(int n)
{
	int	ret;

	ret = 0;
	if (n == -2147483648)
	{
		ret += ret_putchar('-');
		ret += ret_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		ret += ret_putchar('-');
		n *= -1;
	}
	if (n >= 10)
	{
		ret += ret_putnbr(n / 10);
		ret += ret_putnbr(n % 10);
	}
	else
		ret += ret_putchar(n + 48);
	return (ret);
}

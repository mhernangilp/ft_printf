/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_putdec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:07:00 by mhernang          #+#    #+#             */
/*   Updated: 2023/03/07 20:07:21 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	ret_putdec(double n, int abs)
{
	int	i;
	int	ret;

	i = -1;
	ret = 0;
	if (n < 0)
	{
		if (abs == 0)
			ret += ret_putchar('-');
		n *= -1;
	}
	n *= 10000000;
	if ((int)n % 10 >= 5)
		n += 10;
	n /= 10000000;
	ret += ret_putnbr((int) n);
	ret += ret_putchar('.');
	while (++i < 6)
	{
		n *= 10;
		ret += ret_putnbr((int)n % 10);
	}
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:08:51 by mhernang          #+#    #+#             */
/*   Updated: 2023/03/21 15:15:19 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	select_mode(va_list args, char mode)
{
	int	ret;

	ret = 0;
	if (mode == 'c')
		ret = ret_putchar(va_arg(args, int));
	else if (mode == 's')
		ret = ret_putstr(va_arg(args, char *));
	else if (mode == 'p')
		ret = ret_putvoid(va_arg(args, unsigned long long));
	else if (mode == 'd' || mode == 'i')
		ret = ret_putnbr(va_arg(args, int));
	else if (mode == 'u')
		ret = ret_putuns(va_arg(args, unsigned int));
	else if (mode == 'x' || mode == 'X')
		ret = ret_puthex(va_arg(args, unsigned int), mode);
	else if (mode == '%')
		ret = ret_putchar('%');
	return (ret);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		ret;

	ret = 0;
	va_start(args, str);
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%')
			ret += select_mode(args, str[++i]);
		else
			ret += ret_putchar(str[i]);
	}
	va_end(args);
	return (ret);
}

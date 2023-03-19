/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:08:51 by mhernang          #+#    #+#             */
/*   Updated: 2023/03/19 20:54:11 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

static int	select_mode(va_list args, char mode)
{
	int	ret;

	ret = 0;
	if (mode == 'c')
		ret = ret_putchar(va_arg(args, int));
	else if (mode == 's')
		ret = ret_putstr(va_arg(args, char *));
	else if (mode == 'p')
		ret = ret_putvoid(va_arg(args, void *));
	else if (mode == 'd' || mode == 'i')
		ret = ret_putnbr(va_arg(args, int));
	else if (mode == 'u')
		ret = ret_putuns(va_arg(args, unsigned int));
	else if (mode == 'x')
		ret = ret_puthex(va_arg(args, unsigned int));
	else if (mode == 'X')
		ret = ret_puthexx(va_arg(args, unsigned int));
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
		{
			write(1, &str[i], 1);
			ret++;
		}
	}
	va_end(args);
	return (ret);
}

int main(void)
{
	int n = 9;
	printf("No1: %d\n", printf("%p\n", ""));
	printf("No2: %d\n", ft_printf("%p\n", ""));
	return 0;
}

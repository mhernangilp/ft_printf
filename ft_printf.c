/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:08:51 by mhernang          #+#    #+#             */
/*   Updated: 2023/02/28 18:27:21 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	select_mode(va_list args, char mode)
{
	int	ret;

	ret = 0;
	if (mode == 'c')
		ret = ret_putchar(va_arg(args, int));
	else if (mode == 's')
		ret = ret_putstr(va_arg(args, char *));
	else if (mode == 'p')
		ret = 0;	
	else if (mode == 'd')
		ret = ret_putdec(va_arg(args, double));
	else if (mode == 'i')
		ret = ret_putnbr(va_arg(args, int));
	else if (mode == 'u')
		ret = 0;
	else if (mode == 'x')
		ret = 0;
	else if (mode == 'X')
		ret = 0;
	else if (mode == '%')
		ret = 0;
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
	printf("No1: %d\n", printf("Hey %f que tal\n", 12.9999999999));
	printf("No2: %d\n", ft_printf("Hey %d que tal\n", 12.999999999));
	return 0;
}


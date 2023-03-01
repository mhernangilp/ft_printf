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

static void	select_mode(va_list args, char mode)
{
	if (mode == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (mode == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (mode == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;

	va_start(args, str);
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%')
			select_mode(args, str[++i]);
		else
			write(1, &str[i], 1);
	}
	return 0;
}

int main(void)
{
	int	i;

	i = 5;
	printf(" %s \n", "-");
	ft_printf(" %s ", "-");
	return 0;
}


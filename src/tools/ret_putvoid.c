/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_putvoid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:17:51 by mhernang          #+#    #+#             */
/*   Updated: 2023/03/19 20:02:35 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	ret_putvoid(void *ptr)
{
	int		ret;
	char	*str;

	ret = ret_putstr("0x");
	str = ft_itoa_base((unsigned long long) ptr, "0123456789abcdef");
	ret += ret_putstr(str);
	free(str);
	return (ret);
}

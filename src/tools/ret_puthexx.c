/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_puthexx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:15:05 by mhernang          #+#    #+#             */
/*   Updated: 2023/03/19 20:33:47 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	ret_puthexx(unsigned int n)
{
	char	*str;
	int		ret;
	int		i;

	i = -1;
	str = ft_itoa_base(n, "0123456789ABCDEF");
	if (!str)
		return (0);
	ret = ret_putstr(str);
	free(str);
	return (ret);
}

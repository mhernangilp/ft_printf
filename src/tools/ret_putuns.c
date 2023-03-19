/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_putuns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:39:34 by mhernang          #+#    #+#             */
/*   Updated: 2023/03/19 20:47:15 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	ret_putuns(unsigned int n)
{
	char	*str;
	int		ret;

	str = ft_itoa_base(n, "0123456789");
	ret = ret_putstr(str);
	free(str);
	return (ret);
}

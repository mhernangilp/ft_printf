/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_putstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:09:26 by mhernang          #+#    #+#             */
/*   Updated: 2023/03/07 20:09:45 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	ret_putstr(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = -1;
	while (s[++i])
		write (1, &s[i], 1);
	return (i);
}
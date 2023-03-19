/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:49:00 by mhernang          #+#    #+#             */
/*   Updated: 2023/03/19 20:03:31 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static int	getnlen(unsigned long long n, char *base, int base_len)
{
	int	i;

	i = 1;
	while (n >= base_len)
	{
		n /= base_len;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(unsigned long long n, char *base)
{
	char	*str;
	int		len;
	int		base_len;


	base_len = ft_strlen(base);
	len = getnlen(n, base, base_len);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (len--)
	{
		str[len] = base[n % base_len];
		n /= base_len;
	}
	return (str);
}

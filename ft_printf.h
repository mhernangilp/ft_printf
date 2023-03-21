/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:09:05 by mhernang          #+#    #+#             */
/*   Updated: 2023/03/21 15:15:22 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(char const *str, ...);
int		ret_putchar(char c);
int		ret_putstr(char *s);
int		ret_putnbr(int n);
int		ret_puthex(unsigned int n, const char mode);
int		ret_putvoid(unsigned long long ptr);
int		ret_putuns(unsigned int n);
int		ft_strlen(const char *str);
char	*ft_itoa(int n);

#endif

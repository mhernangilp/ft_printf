
#include "ft_printf.h"

int	ret_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

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

int	ret_putnbr(int n)
{
	int	ret;

	ret = 0;
	if (n == -2147483648)
	{
		ret += ret_putchar('-');
		ret += ret_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		ret += ret_putchar('-');
		n *= -1;
	}
	if (n >= 10)
	{
		ret += ret_putnbr(n / 10);
		ret += ret_putnbr(n % 10);
	}
	else
		ret += ret_putchar(n + 48);
	return (ret);
}

int	ret_putdec(double n, int abs)
{
	int	i;
	int	ret;

	i = -1;
	ret = 0;
	if (n < 0)
	{
		if (abs == 0)
			ret += ret_putchar('-');
		n *= -1;
	}
	n *= 10000000;
	if ((int)n % 10 >= 5)
		n += 10;
	n /= 10000000;
	ret += ret_putnbr((int) n);
	ret += ret_putchar('.');
	while (++i < 6)
	{
		n *= 10;
		ret += ret_putnbr((int)n % 10);
	}
	return (ret);
}

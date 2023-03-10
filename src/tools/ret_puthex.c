
#include "../../ft_printf.h"

static int	get_hex_len(int n)
{
	int	i;

	i = 1;
	while (n > 15)
	{
		n /= 16;
		i++;
	}
	return (i);
}

static void	write_hex(char *pos, int value)
{
	if (value < 10)
		*pos = value + '0';
	else
		*pos = value - 10 + 'a';
}

static void	conv_hex(int n, char *wrt, int len)
{
	//printf("Len: %d\n", len);
	wrt[len] = '\0';
	while (--len >= 0)
	{
		if (n > 15)
		{
			//printf("Escribimos en wrt[%d] el valor %d\n", len, n % 16);
			write_hex(&wrt[len], n % 16);
			n /= 16;
		}
		else {
			//printf("Escribimoss en wrt[%d] el valor %d\n", len, n);
			write_hex(&wrt[len], n);
		}
	}
}

static void	neg_hex(char **wrt, int len)
{
	int	i;
	char	*ret;

	i = 8;
	ret = malloc(9 * sizeof(char));
	while (--len >= 0)
	{
		printf("Hola %c\n", *wrt[1]);
		printf("Escribo en ret[%d--] *wrt[%d], valor:%c\n", i--, len,*wrt[0]);
	}
		//ret[i--] = *wrt[len];
	while (i-- > 0)
		ret[i] = 'f';
	free(*wrt);
	*wrt = ret;
}

int	ret_puthex(int n)
{
	char	*wrt;
	int	neg;
	int	ret;
	int	len;

	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n *= -1;
	}
	len = get_hex_len(n);
	wrt = malloc(len + 1);
	conv_hex(n, wrt, len);
	printf("wrt: %s\n", wrt);
	if (neg == 1)
		neg_hex(&wrt, len);
	ret = ret_putstr(wrt);
	return (ret);
}


#include "../../ft_printf.h"

int	ret_puthex(unsigned int n)
{
	char	*str;
	int	ret;

	str = ft_itoa_base(n, "0123456789abcdef");
	ret = ret_putstr(str);
	free(str);
	return (ret);
}

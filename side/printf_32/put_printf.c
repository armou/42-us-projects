#include "libftprintf.h"
#include "libft.h"

void	put_printf(char *str, t_return *ret)
{
	int		i;

	i = 0;
	while(str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	ret->value += i;
}

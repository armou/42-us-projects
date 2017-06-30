#include "libftprintf.h"
#include "libft.h"

void	get_just_max(char *format, t_string *stri)
{
	int		j;

	j = 0;
	while (format[stri->i] >= '0' && format[stri->i] <= '9')
	{
		stri->tmp[j] = format[stri->i];
		stri->i++;
		j++;
	}
	stri->tmp[j] = '\0';
}

void	init_stri(char *format, t_string *stri)
{	
	while (format[stri->i] != '-' && format[stri->i] != '\0' && format[stri->i])
		stri->i++;
	if (format[stri->i] == '-')
		stri->just = -1;
	stri->i = 0;
	while (format[stri->i] != 's' && format[stri->i])
	{
		if (format[stri->i] >= '1' && format[stri->i] <= '9')
		{
			get_just_max(format, stri);
			stri->just *= ft_atoi(stri->tmp);
			if (format[stri->i] == 's')
				stri->i--;
		}
		if (format[stri->i] == '.')
		{
			stri->i++;
			get_just_max(format, stri);
			stri->max = ft_atoi(stri->tmp);
		}
		stri->i++;
	}
}

void	just_pos_less_max(char *str, t_string *stri, t_return *ret)
{
	int		j;

	j = 0;
	while (j < (stri->just - (int)ft_strlen(str)))
	{
		write(1, " ", 1);
		ret->value += 1;
		j++;
	}	
	if (stri->max != 0)
	{
		stri->i = 0;
		while (str[stri->i] && ((j + stri->i) < stri->max))
		{
			write(1, &str[stri->i], 1);
			ret->value += 1;
			stri->i++;
		}
	}
	else
		put_printf(str, ret);
}

void	just_pos_more_max(char *str, t_string *stri, t_return *ret)
{
	int		j;

	j = 0;
	while (j < (stri->just - stri->max))
	{
		write(1, " ", 1);
		ret->value += 1;
		j++;
	}
	stri->i = 0;
	while (str[stri->i] && stri->i < stri->max)
	{
		write(1, &str[stri->i], 1);
		ret->value += 1;
		stri->i++;
	}

}

void	just_neg(char *str, t_string *stri, t_return *ret)
{
	if (stri->max != 0)
	{
		stri->i = 0;
		while (str[stri->i] && stri->i < stri->max)
		{
			write(1, &str[stri->i], 1);
			stri->i++;
		}
		while (stri->i++ < (stri->just * -1))
			write(1, " ", 1);
	}
	else
	{
		stri->i = 0;
		while (str[stri->i])
		{
			write(1, &str[stri->i], 1);
			stri->i++;
		}
		while (stri->i++ < (stri->just * -1))
			write(1, " ", 1);
	}
	ret->value += stri->i - 1;
}

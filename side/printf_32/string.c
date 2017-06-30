#include "libftprintf.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	wide_string(char *format, wchar_t *str, t_return *ret)
{
	t_string	*stri;
	int			j;

	stri = (t_string*)malloc(sizeof(*stri));
	stri->i = 0;
	stri->just = 1;
	stri->max = 0;
	init_stri(format, stri);
	if (stri->just == 1 && stri->max == 0)
		put_printf((char*)str, ret);
	else if (stri->just > 0)
	{
		j = 0;
		if (stri->just < stri->max || stri->max == 0)
			just_pos_less_max((char*)str, stri, ret);
		else
			just_pos_more_max((char*)str, stri, ret);
	}
	else if (stri->just < 0)
		just_neg((char*)str, stri, ret);
}

void	normal_string(char *format, char *str, t_return *ret)
{
	t_string	*stri;
	int			j;

	stri = (t_string*)malloc(sizeof(*stri));
	stri->i = 0;
	stri->just = 1;
	stri->max = 0;
	init_stri(format, stri);
	if (stri->just == 1 && stri->max == 0)
		put_printf(str, ret);
	else if (stri->just > 0)
	{
		j = 0;
		if (stri->just < stri->max || stri->max == 0)
			just_pos_less_max(str, stri, ret);
		else
			just_pos_more_max(str, stri, ret);
	}
	else if (stri->just < 0)
		just_neg(str, stri, ret);
}

void	check_string(char *format, char *str, t_return *ret)
{
	int		i;

	i = 0;
	while (format[i] != 's' && format[i] != 'S' &&
			format[i] != 'l' && format[i] != '\0')
		i++;
	if (format[i] == 's')
		normal_string(format, str, ret);
	if (format[i] == 'S' || format[i] == 'l')
		wide_string(format, (wchar_t*) str, ret);
}

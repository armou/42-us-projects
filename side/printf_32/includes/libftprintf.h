/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 14:38:54 by mabuchwa          #+#    #+#             */
/*   Updated: 2016/02/19 18:52:29 by tcharrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <wchar.h>
# include <locale.h>
#include <unistd.h>

typedef struct		s_string
{
	int				just;
	char			tmp[11];
	int				max;
	int				i;
}					t_string;

typedef struct		s_return
{
	int				value;
}					t_return;

void	put_printf(char *str, t_return *ret);
void	normal_string(char *format, char *str, t_return *ret);
void	check_string(char *format, char *str, t_return *ret);
void	get_just_max(char *format, t_string *stri);
void	init_stri(char *format, t_string *stri);
void	just_pos_less_max(char *str, t_string *stri, t_return *ret);
void	just_pos_more_max(char *str, t_string *stri, t_return *ret);
void	just_neg(char *str, t_string *stri, t_return *ret);

#endif

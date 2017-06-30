/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <aoudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 12:30:25 by aoudin            #+#    #+#             */
/*   Updated: 2017/05/30 17:07:05 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# include "../libs/libft/libft.h"

# define C info->conv
# define CC (*info)->conv
# define M info->mod
# define MM (*info)->mod
# define F info->flags
# define PREC info->precision
# define WIDTH info->width
# define NOMOD (!(MM->hh || MM->h || MM->l || MM->ll || MM->z || MM->j))
# define ABS(x) (x < 0) ? -x : x
# define PF_BUFFSIZE 64

typedef struct s_flag	t_flag;
typedef struct s_mod	t_mod;
typedef struct s_info	t_info;
typedef struct s_conv	t_conv;

struct	s_flag
{
	int		sharp;
	int		minus;
	int		plus;
	int		space;
	int		zero;
	int		wstar;
	int 	pstar;
	int		dot;
	int		wstar_pri;
	int		pstar_pri;
	int		printed;
};

struct	s_mod
{
	int		hh;
	int		h;
	int		l;
	int		ll;
	int		j;
	int		z;
};
struct	s_conv
{
	int		s;
	int		p;
	int		d;
	int		o;
	int		u;
	int		x;
	int		xx;
	int		c;
	int		perc;
	int		unprint;
	wchar_t	extra;
};

struct      s_info
{
	t_flag	*f;
	t_mod	*m;
	t_conv	*c;
    int     width;
	int 	padding;
    int     precision;
	int 	b_index;
	char 	buff[PF_BUFFSIZE];
	char	*fmt;
	int 	len;
	void	(*fptr_f[5])(void *);
	void	(*fptr_m[6])(void *);
	void	(*fptr_c[14])(void *);
};

int         ft_printf(const char *str, ...);
void		ft_buff(t_info *p, void *newstr, int size);
void    	pf_putstr(t_info *p, va_list ap);
void    	pf_putnbr(t_info *p, va_list ap);
void		pf_putchar(t_info *p, unsigned c);
void		pf_putwchar(t_info *p, unsigned int wc, int bytes);
void		pf_putoct(t_info *p, va_list ap);
void		ft_putoctal(unsigned long long nb);
void		ft_itoa_base_printf(t_info *p, uintmax_t nb, int base);
void		ft_itoa_printf(t_info *p, intmax_t nb);
void    	pf_printhexa(t_info *p, va_list ap);
void		pf_printaddr(t_info *p, va_list ap);
void 		ft_flags(t_info *p);
void		ft_padding(t_info *p, int n);
intmax_t 	ft_find_type(t_info *p, va_list ap);
uintmax_t	ft_find_utype(t_info *p, va_list ap);


#endif
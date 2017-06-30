/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <aoudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 21:35:27 by aoudin            #+#    #+#             */
/*   Updated: 2017/05/24 15:13:18 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
/*
void	ftpf_manage_lenmod_di_sub(va_list *ap, t_env *e, char **itoa_ret)
{
	if (!ft_strcmp(e->mod, "h"))
	{
		if ((e->param->sh = (int)va_arg(*ap, int)) < 0)
			e->isneg = 1;
		*itoa_ret = ft_itoa(e->param->sh);
	}
	else if (!ft_strcmp(e->mod, "ll"))
	{
		if ((e->param->ll = (long long)va_arg(*ap, long long)) < 0)
			e->isneg = 1;
		*itoa_ret = ft_itoa_ll(e->param->ll, 10);
	}
	else if (!ft_strcmp(e->mod, "j"))
	{
		if ((e->param->imax = (intmax_t)va_arg(*ap, intmax_t)) < 0)
			e->isneg = 1;
		*itoa_ret = ft_itoa_ll(e->param->imax, 10);
	}
	else if (!ft_strcmp(e->mod, "z"))
	{
		if ((e->param->l = (long)va_arg(*ap, long)) < 0)
			e->isneg = 1;
		*itoa_ret = ft_itoa_ll(e->param->l, 10);
	}
}

int	ft_manage_lenmod_s(va_list *ap, t_info *p)
{
	char	*str;

	if (p->m->l || p->conversion == 'S')
		ftpf_manage_lenmod_s_wide(ap, p);
	else
	{
		str = (char*)va_arg(*ap, char*);
		if (str)
		{
			p->len += ft_strlen(str);
		}
		else
			ftpf_s_nullexception(e);
	}
	return (str);
}

int 	ft_lenmod(t_info *p, va_list ap)
{


}
/*
void    handle_flags(t_info *p, va_list ap)
{
    if (p->f->sharp)// rajouter la conversion 'p'
        execute_sharp(p); // faire une vrai fonction
    if (p->f->zero && !p->f->minus) // conditions non complete
        p->padder = '0';// trouver une variable a assigner
    if (p->f->zero && p->f->minus /* && precision flag )
		p->f->zero = 0;
    if (p->f->space && !p->f->minus && !p->f->plus/* && conversion dDi )
		{
			p->len++;
		}
    if (p->f->plus /* && conversion dDi )
		{
			if (!p->f->plus)
			{
				p->len++;

			}
			else
				p->f->plus = 0;
		}
		
        
}

*/
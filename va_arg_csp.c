/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_arg_csp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrankul <vgrankul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 14:08:09 by vgrankul          #+#    #+#             */
/*   Updated: 2020/02/06 14:43:55 by vgrankul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_va_arg_float(t_format_struct *new, va_list ap)
{
	long double n;
	char *str;

	n = 0;
	if(new->length[0] == '\0' || new->length[0] == 'l')
	{
		n = va_arg(ap, double);
	//	str = ft_itoa_double(n, new->precision);
	}
	else if (new->length[0] == 'L')
		n =  va_arg(ap, long double);
	if (new->precision == 0)
		str = ft_itoa_double(n, 6);
	else if (new->precision == -1)
		str = ft_itoa_double(n, 0);
	else
		str = ft_itoa_double(n, new->precision);
	ft_check_flags_float(str, new);
}
void	ft_va_arg_char(t_format_struct *new, va_list ap)
{
	char n;
	int a;
	char str[2];

	if (new->conv_char == '%')
		n = '%';
	else
	{
	a = va_arg(ap, int);
	n = (unsigned char)a;
	}
	str[0] = n;
	str[1] = '\0';
	ft_check_flags_char(str, new);
}

void	ft_va_arg_string(t_format_struct *new, va_list ap)
{
	char *str;
                    
	str = va_arg(ap, char*);
	ft_check_flags_string(str, new);
}

void	ft_va_arg_mem(t_format_struct *new, va_list ap)
{
	long long n;
	char *str;

	n = va_arg(ap, long long);
	str = ft_string_tolower(ft_hex(n));
	str = ft_add_ox(str, new);
	ft_check_flags_char(str, new);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_arg_csp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrankul <vgrankul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 14:08:09 by vgrankul          #+#    #+#             */
/*   Updated: 2020/02/14 14:58:39 by vgrankul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_va_arg_float(t_format_struct *new, va_list ap)
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
		
	if (new->prec == 1)
	{
		//if (new->precision == 0)
		//	str = ft_itoa_double(n, 1);
		//else
			//if (new->precision >= 18)
			//	str = ft_itoa_double(n, 18, new);
		//	else
				str = ft_itoa_double(n, new->precision, new);
	}
	else
		str = ft_itoa_double(n, 6, new);
	return(ft_check_flags_float(str, new));
}
int	ft_va_arg_char(t_format_struct *new, va_list ap)
{
	char n;
	int a;
	char *str;

	str = (char*)malloc(1 * sizeof(char) + 1);
	if (new->conv_char == '%')
		n = '%';
	else
	{
	a = va_arg(ap, int);
	n = (unsigned char)a;
	}
	str[0] = n;
	str[1] = '\0';
	return(ft_check_flags_char(str, new));
}

int	ft_va_arg_string(t_format_struct *new, va_list ap)
{
	char *str;
          
	str = va_arg(ap, char*);
	return(ft_check_flags_string(str, new));
}

int	ft_va_arg_mem(t_format_struct *new, va_list ap)
{
	long long n;
	char *str;
	
	n = va_arg(ap, long long);
	str = ft_string_tolower(ft_hex(n));
	str = ft_add_ox(str, new);
	return(ft_check_flags_char(str, new));
	
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrankul <vgrankul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:07:26 by vgrankul          #+#    #+#             */
/*   Updated: 2020/02/06 14:43:50 by vgrankul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_set_to_zero (t_format_struct *new)
{
	new->width = 0;
	new->precision = 0;
	new->f_hash = 0;
	new->f_zero = 0;
	new->f_minus = 0;
	new->f_plus = 0;
	new->f_space = 0;
}

void ft_set_flag(char c, t_format_struct *new)
{
	if (c == '#')
		new->f_hash = 1;
	else if (c == '0')
		new->f_zero = 1;
	else if (c == '-')
		new->f_minus = 1;
	else if (c == '+')
		new->f_plus = 1;
	else if (c == ' ')
		new->f_space = 1;

}
int ft_is_flag(char c)
{
	if (c == '#' || c == '0' || c == '-' || c == '+' || c == ' ')
		return (1);
	else
		return (0);
}
int	ft_is_conv_char(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 'f')
		return (1);
	else
		return (0);
}

void	ft_check_conv_char(t_format_struct *new, va_list ap)
{
	if (new->conv_char == 'd' || new->conv_char == 'i')
		ft_va_arg_int(new, ap);
	else if (new->conv_char == 'o')
		ft_va_arg_octal(new, ap);
	else if (new->conv_char == 'u')
		ft_va_arg_unsigned_int(new, ap);
	else if (new->conv_char == 'x' || new->conv_char == 'X')
		ft_va_arg_hex(new, ap);
	else if (new->conv_char == 'f')
		ft_va_arg_float(new, ap);
	else if (new->conv_char == 'c')
		ft_va_arg_char(new, ap);
	else if (new->conv_char == 's')
		ft_va_arg_string(new, ap);
	else if(new->conv_char == 'p')
		ft_va_arg_mem(new, ap);
	else if(new->conv_char == '%')
		ft_va_arg_char(new, ap);
}
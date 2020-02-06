/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrankul <vgrankul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:07:26 by vgrankul          #+#    #+#             */
/*   Updated: 2020/02/06 16:46:45 by vgrankul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_flags_diouxx(char *str, t_format_struct *new)
{
	char *str2;

	str2 = str;
	
	if (new->conv_char == 'o' && new->f_hash == 1)
	{
		str2 = str;
		new->precision = ft_strlen(str) + 1;
	}
	if (new->precision > 0)
	{
		str2 = str;
		new->f_zero = 0;
		if (new->precision > (int)ft_strlen(str))
			str = ft_set_zero (str, new);
	}
	if ((new->conv_char == 'x' || new->conv_char == 'X') && new->f_hash == 1)
	{
		str2 = str;
		str = ft_add_ox(str, new);
	}
	if ((new->conv_char == 'd' || new->conv_char == 'i') && new->f_plus == 1)
	{
		new->f_space = 0;
			str = ft_set_sign(str, '+');
	}
	if ((new->conv_char == 'd' || new->conv_char == 'i') && new->f_space == 1)
		str = ft_set_sign(str, ' ');
	if (new->width != 0 && new->width > (int)ft_strlen(str))
	{
		str2 = str;
		if(new->f_minus == 1)
		{
			new->f_zero = 0;
			str = ft_set_space(str, new, ' ');
		}
		else if (new->f_zero == 1)
			str = ft_set_space(str, new, '0');
		else if (new ->f_zero != 1)
			str = ft_set_space(str, new, ' ');
	}
	//system("leaks a.out");
	//ft_putstr(str);
	ft_putstr(str);
	free(str2);
	free(str);

}
void	ft_check_flags_float(char *str, t_format_struct *new)
{
	int len;
	char *str2;

	str2 = str;
	len = count_to_dot(str);
	if (new->f_hash == 1 && new->precision == -1)
	{
		str2 = str;
		str = ft_copy_string(str, len);
	}
	else if (new->precision > 0 || new->precision == -1)
	{
		str2 = str;
		new->f_zero = 0;
		if (new->precision == -1)
			str = ft_copy_string(str, len - 1);
		else if (new->precision > (int)ft_strlen(str))
			str = ft_set_zero (str, new);
		else if (new->precision < (int)ft_strlen(str))
			str = ft_copy_string(str,len + new->precision);
	}
	if (new->f_plus == 1)
	{
		new->f_space = 0;
		str = ft_set_sign(str, '+');
	}
	if (new->f_space == 1)
		str = ft_set_sign(str, ' ');
	if (new->width != 0 && new->width > (int)ft_strlen(str))
	{
		str2 = str;
		if(new->f_minus == 1)
		{
			new->f_zero = 0;
			str = ft_set_space(str, new, ' ');
		}
		else if (new->f_zero == 1)
			str = ft_set_space(str, new, '0');
		else
			str = ft_set_space(str, new, ' ');
}
	ft_putstr(str);
	free(str);
	free(str2);

}
void 	ft_check_flags_char(char *str, t_format_struct *new)
{
	char *str2;

	str2 = str;
	if (new->width != 0 && new->width > (int)ft_strlen(str))
	{
		str2 = str;
		str = ft_set_space(str, new, ' ');
	}
	ft_putstr(str);
	free(str);
	free(str2);
}

void 	ft_check_flags_string(char *str, t_format_struct *new)
{
	char *str2;

	str2 = str;
	if (new->precision != 0 && new->precision < (int)ft_strlen(str))
	{
		str2 = str;
		str = ft_copy_string(str, new->precision);
	}
	if (new->width != 0 && new->width > (int)ft_strlen(str))
	{
		str2 = str;
		str = ft_set_space(str, new, ' ');
	}
	ft_putstr(str);
	free(str);
	free(str2);
		
}

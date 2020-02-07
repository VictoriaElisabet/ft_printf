/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrankul <vgrankul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:07:26 by vgrankul          #+#    #+#             */
/*   Updated: 2020/02/07 16:15:37 by vgrankul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_flags_diouxx(char *str, t_format_struct *new)
{
	char *tmp;

	tmp = ft_strnew(ft_strlen(str));	
	if (new->conv_char == 'o' && new->f_hash == 1)
	{
		new->precision = ft_strlen(str) + 1;
	}
	if (new->precision > 0)
	{
		//tmp = str;
		new->f_zero = 0;
		if (new->precision > (int)ft_strlen(str))
			tmp = ft_set_zero (str, new);
			str = tmp;
	}
	if ((new->conv_char == 'x' || new->conv_char == 'X') && new->f_hash == 1)
	{
		//tmp = str;
		tmp = ft_add_ox(str, new);
		str = tmp;
	}
	if ((new->conv_char == 'd' || new->conv_char == 'i') && new->f_plus == 1)
	{
		new->f_space = 0;
			tmp = ft_set_sign(str, '+');
			str = tmp;
	}
	if ((new->conv_char == 'd' || new->conv_char == 'i') && new->f_space == 1)
	{
		tmp = ft_set_sign(str, ' ');
		str = tmp;
	}
	if (new->width != 0 && new->width > (int)ft_strlen(str))
	{
		//tmp = str;
		if(new->f_minus == 1)
		{
			new->f_zero = 0;
			tmp = ft_set_space(str, new, ' ');
		}
		else if (new->f_zero == 1)
		{
			tmp = ft_set_space(str, new, '0');
		}
		else if (new ->f_zero != 1)
			tmp = ft_set_space(str, new, ' ');
			str = tmp;
	}
	ft_putstr(str);
	free(tmp);
//	system("leaks a.out");
	return (ft_strlen(str));
	//free(str);

}
int	ft_check_flags_float(char *str, t_format_struct *new)
{
	int len;
	char *tmp;

	tmp = str;
	len = count_to_dot(str);
	if (new->f_hash == 1 && new->precision == -1)
	{
		tmp = str;
		str = ft_copy_string(str, len);
	}
	else if (new->precision > 0 || new->precision == -1)
	{
		tmp = str;
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
		tmp = str;
		if(new->f_minus == 1)
		{
			new->f_zero = 0;
			str = ft_set_space(str, new, ' ');
		}
		else if (new->f_zero == 1)
			str = ft_set_zero(str, new);
		else
			str = ft_set_space(str, new, ' ');
}
	ft_putstr(str);
//	free(str);
	free(tmp);
	return(ft_strlen(str));

}
int 	ft_check_flags_char(char *str, t_format_struct *new)
{
	char *tmp;

	tmp = ft_strnew(ft_strlen(str));
	if (new->width != 0 && new->width > (int)ft_strlen(str))
	{
		tmp = ft_set_space(str, new, ' ');
		str = tmp;
	}
	ft_putstr(str);
	//free(str);
	free(tmp);

	return(ft_strlen(str));
}

int 	ft_check_flags_string(char *str, t_format_struct *new)
{
	char *tmp;

	tmp = ft_strnew(ft_strlen(str));
	if (new->precision != 0 && new->precision < (int)ft_strlen(str))
	{
		tmp = ft_copy_string(str, new->precision);
		str = tmp;
	}
	if (new->width != 0 && new->width > (int)ft_strlen(str))
	{
		tmp = ft_set_space(str, new, ' ');
		str = tmp;
	}
	ft_putstr(str);
	free(tmp);
	
	return(ft_strlen(str));

		
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags_float.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrankul <vgrankul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:07:26 by vgrankul          #+#    #+#             */
/*   Updated: 2020/02/20 09:18:19 by vgrankul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*float_prec(char *str, char *tmp, t_format_struct *new)
{
	int len;

	len = count_to_dot(str);
	tmp = str;
	if (new->precision == 0 && new->prec == 1)
		str = ft_copy_string(str, len - 1);
	else if ((ft_strlen(str) - count_to_dot(str)) < (size_t)new->precision)
		str = ft_add_zero_float(str, new->precision -
				((int)ft_strlen(str) - count_to_dot(str)), len, 0);
	else if ((ft_strlen(str) - count_to_dot(str)) > (size_t)new->precision)
		str = ft_copy_string_float(str, new, len);
	return (str);
}

char	*float_width(char *str, char *tmp, t_format_struct *new)
{
	tmp = str;
	if (new->f_minus == 1)
	{
		new->f_zero = 0;
		str = ft_set_space(str, new, ' ');
	}
	else if (new->f_zero == 1)
	{
		str = ft_set_space(str, new, '0');
	}
	else
		str = ft_set_space(str, new, ' ');
	return (str);
}

char	*plus_sign_float(char *str, char *tmp, t_format_struct *new)
{
	new->f_space = 0;
	tmp = str;
	str = ft_set_sign(str, '+');
	return (str);
}

char	*hash_float(char *str, char *tmp, t_format_struct *new)
{
	int len;

	len = count_to_dot(str);
	tmp = str;
	new->prec = 0;
	str = ft_copy_string(str, len);
	return (str);
}

int		ft_check_flags_float(char *str, t_format_struct *new)
{
	char *tmp;

	tmp = str;
	if (new->f_hash == 1 && new->precision == 0)
		str = hash_float(str, tmp, new);
	else if (ft_strlen(str) - count_to_dot(str) < 6 && new->prec != 1)
	{
		tmp = str;
		str = ft_add_zero_float(str, 6 - (ft_strlen(str) -
					count_to_dot(str)), count_to_dot(str), 0);
	}
	if (new->precision >= 0 && new->prec == 1)
		str = float_prec(str, tmp, new);
	if (new->f_plus == 1)
		str = plus_sign_float(str, tmp, new);
	if (new->f_space == 1)
		str = ft_set_sign(str, ' ');
	if (new->width != 0 && new->width > (int)ft_strlen(str))
		str = float_width(str, tmp, new);
	ft_putstr(str);
	free(tmp);
	return (ft_strlen(str));
}

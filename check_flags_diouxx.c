/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags_diouxx.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrankul <vgrankul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:07:26 by vgrankul          #+#    #+#             */
/*   Updated: 2020/02/20 08:44:44 by vgrankul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*diouxx_width(char *str, char *tmp, t_format_struct *new)
{
	if (new->f_minus == 1)
	{
		new->f_zero = 0;
		tmp = ft_set_space(str, new, ' ');
	}
	else if (new->f_zero == 1)
	{
		tmp = ft_set_space(str, new, '0');
	}
	else if (new->f_zero != 1)
		tmp = ft_set_space(str, new, ' ');
	str = tmp;
	return (str);
}

char	*diouxx_prec(char *str, char *tmp, t_format_struct *new)
{
	int len;
	int preclen;

	if (str[0] == '-' || str[0] == '+')
		new->precision = new->precision + 1;
	len = (new->precision - ft_strlen(str)) + ft_strlen(str);
	preclen = new->precision - ft_strlen(str);
	if (new->prec != 2)
		new->f_zero = 0;
	if (new->precision == 0 && new->prec == 1 && new->f_hash != 1)
		tmp = ft_copy_string(str, 0);
	if (new->precision > (int)ft_strlen(str))
		tmp = ft_add_zero_diouxx(str, len, preclen);
	str = tmp;
	return (str);
}

void	octal_hash_exception(char *str, t_format_struct *new)
{
	if (new->precision == 0 && new->prec == 0 && str[0] != '0')
	{
		new->precision = ft_strlen(str) + 1;
		new->prec = 2;
	}
	if (new->precision <= (int)ft_strlen(str) && str[0] != '0')
	{
		new->precision = ft_strlen(str) + 1;
		new->prec = 1;
	}
}

char	*plus_sign_diouxx(char *str, char *tmp, t_format_struct *new)
{
	new->f_space = 0;
	tmp = ft_set_sign(str, '+');
	str = tmp;
	return (str);
}

int		ft_check_flags_diouxx(char *str, t_format_struct *new)
{
	char *tmp;

	tmp = str;
	if (new->conv_char == 'o' && new->f_hash == 1)
		octal_hash_exception(str, new);
	if (new->precision >= 0 && (new->prec == 1 || new->prec == 2))
		str = diouxx_prec(str, tmp, new);
	if ((new->conv_char == 'd' || new->conv_char == 'i') && new->f_plus == 1)
		str = plus_sign_diouxx(str, tmp, new);
	if ((new->conv_char == 'd' || new->conv_char == 'i') && new->f_space == 1)
	{
		tmp = ft_set_sign(str, ' ');
		str = tmp;
	}
	if ((new->conv_char == 'x' || new->conv_char == 'X') && new->f_hash == 1)
	{
		tmp = ft_add_ox(str, new);
		str = tmp;
	}
	if (new->width != 0 && new->width > (int)ft_strlen(str))
		str = diouxx_width(str, tmp, new);
	ft_putstr(str);
	free(tmp);
	return (ft_strlen(str));
}

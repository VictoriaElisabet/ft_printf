/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrankul <vgrankul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 12:52:28 by vgrankul          #+#    #+#             */
/*   Updated: 2020/02/19 17:19:45 by vgrankul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*double_first(long long first, long double nb)
{
	char *str;
	char *tmp;

	if (!(tmp = ft_itoa(first)))
		return (NULL);
	str = tmp;
	if (nb < 0)
	{
		if (!(tmp = ft_strjoin("-", str)))
			return (NULL);
	}
	str = tmp;
	if (!(tmp = ft_strjoin(str, ".")))
		return (NULL);
	str = tmp;
	return (str);
}

char	*double_join(long long first,
		long long second, long double nb)
{
	int		len;
	char	*tmp;
	char	*str;

	len = set_len(first, second, nb);
	if (!(str = (char*)malloc((sizeof(char) * (len + 1)))))
		return (NULL);
	tmp = double_first(first, nb);
	str = tmp;
	if (second == 0)
	{
		if (!(tmp = ft_strdup("000000")))
			return (NULL);
	}
	else
	{
		if (!(tmp = ft_itoa(second)))
			return (NULL);
	}
	if (!(tmp = ft_strjoin(str, tmp)))
		return (NULL);
	str = tmp;
	return (str);
}

char	*double_preclen_rounding(long long first,
		long long second, int dlen, long double nb)
{
	long long ttmp;

	ttmp = second;
	if (ttmp % 10 == 8)
	{
		ttmp = ttmp / 10;
		dlen--;
	}
	while (ttmp % 10 == 9)
	{
		ttmp = ttmp / 10;
		dlen--;
	}
	if (dlen == 0 && ft_count_digits(second, 10) >= 7)
	{
		first = first + 1;
		second = 0;
	}
	else if (second % 10 >= 5)
		second = second + 10 - second % 10;
	second = second / 10;
	return (double_join(first, second, nb));
}

char	*double_rounding(long long first,
		long long second, t_format_struct *new, long double nb)
{
	int		dlen;

	dlen = ft_count_digits(second, 10);
	if (new->precision == 0 && new->prec == 1)
	{
		if (second % 10 >= 5)
		{
			first = first + 1;
			second = 0;
		}
	}
	if (new->prec != 1)
		return (double_preclen_rounding(first, second, dlen, nb));
	else if (second % 10 >= 5 && new->prec != 0)
		second = second + 10 - second % 10;
	second = second / 10;
	return (double_join(first, second, nb));
}

char	*double_float(double n, int precision, t_format_struct *new)
{
	long long	first;
	long long	second;
	long double	temp;
	long double	nb;

	nb = n;
	if (n < 0)
		n = n * -1;
	second = 0;
	first = (long long)n;
	temp = (n - first);
	while (precision >= 0)
	{
		temp = temp * 10;
		second = (second * 10) + (long long)temp;
		temp = temp - (long long)temp;
		precision--;
	}
	return (double_rounding(first, second, new, nb));
}

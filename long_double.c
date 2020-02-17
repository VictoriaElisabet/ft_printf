/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_double.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrankul <vgrankul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 12:52:28 by vgrankul          #+#    #+#             */
/*   Updated: 2020/02/17 18:29:45 by vgrankul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		count_digits(long long n)
{
	int i;

	i = 0;
	if (n < 0)
		i++;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
void    long_double_rounding(long long *first, long long *second, int preclen, t_format_struct *new)
{
    long long ttmp;
    int dlen;

    dlen = count_digits(*second);
    if (new->precision == 0 && new->prec == 1)
	{
		if(*second%10 >= 5)
		{
			*first = *first + 1;
			*second = 0;
		}
	}
	if (preclen == 6)
	{
		ttmp = second;
		if (ttmp%10 == 8)
		{
			ttmp = ttmp / 10;
			dlen--;
		}
		while (ttmp % 10 == 9)
		{
			ttmp = ttmp / 10;
			dlen--;
		}
		if (dlen == 0 && count_digits(second) >= 7)
		{
			*first = *first + 1;
			*second = 0;
		}
		else if (*second % 10 >= 5)
			*second = *second + 10 - *second % 10;
	}
	else if (*second%10 >= 5 && preclen != 6)
			*second = *second+10 - *second%10;
	*second = *second /10;
}
char    *long_double(long double n, int precision, t_format_struct *new)
{
    long long first;
    long long second;
    long double temp;
    int preclen;

    first = (long long)n;
	temp = (n - first);
    preclen = precision;
    if (n < 0)
		n = n * -1;
    while (precision >= 0)
	{
		temp = temp * 10;	
		second = (second * 10) + (long long)temp;
		temp = temp - (long long)temp;
		precision--;
	}
    long double rounding(first, second);


}
char			*ft_itoa_long_double(long double n, int precision, t_format_struct *new)
{
	char		*str;
	char		*tmp;
	int			len;
	//long long	first;
	//long long	second;
	long double nb;
//	long long ttmp;
	//long double temp;
	//int dlen;
	int i;
	int j;
//	int preclen;

i = 0;
j = 0;
//dlen = 0;
	nb = n;
	//if (n < 0)
	//	n = n * -1;
	//second = 0;
	//first = (long long)n;
//	temp = (n - first);
	//preclen = precision;
//	while (precision >= 0)
//	{
//		temp = temp * 10;	
	//	second = (second * 10) + (long long)temp;
//		temp = temp - (long long)temp;
//		precision--;
///
//	}
//	if (new->precision == 0 && new->prec == 1)
/*	{
		if(second%10 >= 5)
		{
			first = first + 1;
			second = 0;
		}
	}
	if (preclen == 6)
	{
	
		ttmp = second;
		dlen = count_digits(second);
		if (ttmp%10 == 8)
		{
			ttmp = ttmp / 10;
			dlen--;
		}
		while (ttmp % 10 == 9)
		{
	
			ttmp = ttmp / 10;

			dlen--;

		}

		if (dlen == 0 && count_digits(second) >= 7)
		{
			first = first + 1;
			second = 0;
		}
		else if (second % 10 >= 5)
			second = second + 10 - second % 10;

	}
	else if (second%10 >= 5 && preclen != 6)
	{	
			second = second+10 - second%10;


	}
	second = second /10;*/
	if (second == 0)
		len = count_digits(first) + count_digits(second) + 7;
	else if (nb < 0)
		len = count_digits(first) + count_digits(second) + 3;
	else
		len = count_digits(first) + count_digits(second) + 2;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL); 
	if (!(tmp = ft_itoa(first)))
		return (NULL);
	str = tmp;
	if (nb < 0)
		tmp = ft_strjoin("-", str);
	str = tmp;
	if (!(tmp = ft_strjoin(str, ".")))
		return (NULL);
	str = tmp;
	if (second == 0)
	{
		if (!(tmp = ft_strnew(6)))
			return (NULL);
		tmp = ft_memset(tmp, '0', 6);
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrankul <vgrankul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 12:52:28 by vgrankul          #+#    #+#             */
/*   Updated: 2020/02/13 14:38:01 by vgrankul         ###   ########.fr       */
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
int		ft_is_round(long long second)
{
	int len;
	int arr[count_digits(second)];
	int i;

	i = 0;
	len = count_digits(second);
	while (i < len)
	{
		arr[i] = second % 10;
		second = second / 10;
		i++;
	}
	if (arr[0] >= 5)
		return (1);
	else
		return(0);	
	
}

#include <stdio.h>
char			*ft_itoa_double(long double n, int precision, t_format_struct *new)
{
	char		*str;
	char		*tmp;
	int			len;
	long long	first;
	long long	second;
	long double test;
	long double nb;
	long long ttmp;
	long long temp;
	int dlen;
	int i;

new = 0;
i = 0;
dlen = 0;
	nb = n;
	if (n < 0)
		n = n * -1;
	first = (long long)n;
	test = n - first;
	//printf("%Lf\n", test);
	while (precision >= 0)
	{
		test =  test * 10;
		temp = (long long)test;
		test = test - temp;
	//	printf("%lld\n", temp);
		second = (second * 10) + temp;
		precision--;
	//	printf("%Lf\n", test);
	}
	first = (long long)n;
	//second = (long long)((n - first) * (ft_power_of(10, precision + 1) + 0.5)); /*+ (n < 0 ? 0.5 : 0.5)))*/
	//second = (long long)test;
	//ft_putnbr(second);
	if (precision == 0)
	{
		if(second > 5)
			first = first + 1;
	}
	
	else if (second%10 >= 5/*== 9 || second%10 == 8*/)
	{	
			ttmp = second;
			dlen = count_digits(second);
			//ttmp = ttmp / 10;
				//ft_putstr("hii");
			while (ttmp%10 > 5)
			{
				//ft_putstr("hii");
				ttmp = ttmp / 10;
				i++;
				
			}
			/*while (ttmp%10 == 9)
			{
				//ft_putstr("hii");
				ttmp = ttmp / 10;
				i++;
				
			}*/

			//second += 10 - second%10;
			if (i > 6)
				{
					first = first + 1;
					second = 0;
				}
			else
			{
			second = second+10 - second%10;//second + ft_power_of(10, i) - second%ft_power_of(10, i);
			}
}
//else if (second%10 >= 5)
//	second = second + 10 - second%10;
	//}
	second = second /10;
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

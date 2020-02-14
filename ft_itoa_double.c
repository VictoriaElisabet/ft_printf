/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrankul <vgrankul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 12:52:28 by vgrankul          #+#    #+#             */
/*   Updated: 2020/02/14 15:27:07 by vgrankul         ###   ########.fr       */
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

char			*ft_itoa_double(long double n, int precision, t_format_struct *new)
{
	char		*str;
	char		*tmp;
	int			len;
	long long	first;
	long long	second;
	long double nb;
	long long ttmp;
	long double temp;
	int dlen;
	int i;
	int j;

i = 0;
j = 0;
dlen = 0;
	nb = n;
	if (n < 0)
		n = n * -1;
	//n = n + (n > 0 ? 0.1 : -0.5); 
	first = (long long)n;
	temp = (n - first);
	//printf("%Lf\n", test);
	while (precision >= 0)
	{
		temp =  temp * 10;
		//temp = (long long)test;
		second = (second * 10) + (long long)temp;
		
		temp = temp - (long long)temp;
	//	printf("%lld\n", temp);
	//	second = (second * 10) + temp;  
		precision--;
	//	printf("%Lf\n", test);
	}
	//if(second%10 == 0)
		//second = second/10;
//	first = (long long)n;
	//second = (long long)((n - first) * (ft_power_of(10, precision + 1) + 0.5)); /*+ (n < 0 ? 0.5 : 0.5)))*/
	//second = (long long)test;
	//ft_putnbr(second);
	if (new->precision == 0 && new->prec == 1)
	{
		if(second%10 >= 5)
		{
			first = first + 1;
			second = 0;
		}
	}
	
	//if (second%10 >= 5)
	//	second = second+10 - second%10;
	//second = second /10;
	
	if (second%10 >= 5)
	{	
			ttmp = second;
			dlen = count_digits(second);
			//ft_putnbr(dlen);

			//ttmp = ttmp / 10;
				//ft_putstr("hii");
			while (ttmp%10 > 5)
			{
				if(ttmp%10 == 9)
					j++;
				//second = second+10 - second%10;
				//ft_putstr("hii");
				//if(second%10 == 9)
				ttmp = ttmp / 10;
				i++;
				dlen--;
				
			}
			//if (ttmp%10 == 9 && )new-
			//while (ttmp%10 == 9)
			//{
			//	//ft_putstr("hii");
			//	ttmp = ttmp / 10;
			//	i++;
			//	
		//	}
		//ft_putnbr(j);

			//second += 10 - second%10;
		
			//ft_putnbr(dlen);
			if (dlen == 0 )
				{
					first = first + 1;
					second = 0;
				}
			else
				second = second+10 - second%10;//second + ft_power_of(10, i) - second%ft_power_of(10, i);


	}


//else if (second%10 >= 5)
//	second = second + 10 - second%10;
	//}
	//second = second+10 - second%10;
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

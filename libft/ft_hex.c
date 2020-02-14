/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrankul <vgrankul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 12:52:28 by vgrankul          #+#    #+#             */
/*   Updated: 2020/02/12 13:37:23 by vgrankul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		n = n / 16;
		i++;
	}
	return (i);
}

char			*ft_hex(long long n)
{
	char		*str;
	int			len;
	long long	nb;
	int			temp;

	nb = n;
	len = count_digits(n);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len--] = '\0';
	if(n == 0)
		str[len--] = '0';
	while (nb > 0)
	{
		temp = nb % 16;
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + 55;
		str[len--] = temp;
		nb = nb / 16;
	}
	return (str);
}

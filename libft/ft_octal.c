/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrankul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 12:52:28 by vgrankul          #+#    #+#             */
/*   Updated: 2020/01/27 15:20:10 by vgrankul         ###   ########.fr       */
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
		n = n / 8;
		i++;
	}
	return (i);
}

char			*ft_octal(long long n)
{
	char		*str;
	int			len;
	long long	nb;

	nb = n;
	len = count_digits(n);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len--] = '\0';
	if (nb == 0)
		str[len--] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		str[len--] = (nb % 8) + '0';
		nb = nb / 8;
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrankul <vgrankul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 12:52:28 by vgrankul          #+#    #+#             */
/*   Updated: 2020/02/27 16:02:17 by vgrankul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_hex(unsigned long long n)
{
	char				*str;
	int					len;
	unsigned long long	nb;
	int					temp;

	nb = n;
	len = ft_count_udigits(n, 16);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
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

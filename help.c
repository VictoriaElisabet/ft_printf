/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrankul <vgrankul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 12:52:28 by vgrankul          #+#    #+#             */
/*   Updated: 2020/02/19 14:58:56 by vgrankul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		set_len(long long first, long long second, long double nb)
{
	int len;

	if (second == 0)
		len = ft_count_digits(first, 10) + ft_count_digits(second, 10) + 7;
	else if (nb < 0)
		len = ft_count_digits(first, 10) + ft_count_digits(second, 10) + 3;
	else
		len = ft_count_digits(first, 10) + ft_count_digits(second, 10) + 2;
	return (len);
}

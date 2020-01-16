/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrankul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:26:47 by vgrankul          #+#    #+#             */
/*   Updated: 2020/01/16 10:19:12 by vgrankul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"

# define CONV_CHAR 'c', 's', 'p', 'd', 'i', 'o', 'u', 'x', 'X', 'f'

typedef struct	format
{
	int f_hash;
	int f_zero;
	int f_minus;
	int f_plus;
	int f_space;
	int width;
	int precision;
	char length[2];
	char conv_char;

}				format_struct;

#endif

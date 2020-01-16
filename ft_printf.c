/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrankul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:07:26 by vgrankul          #+#    #+#             */
/*   Updated: 2020/01/16 12:06:50 by vgrankul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>
void ft_set_flag(char c, format_struct *new)
{
	if (c == '#')
		new->f_hash = 1;
	else if (c == '0')
		new->f_zero = 1;
	else if (c == '-')
		new->f_minus = 1;
	else if (c == '+')
		new->f_plus = 1;
	else if (c == ' ')
		new->f_space = 1;

}
int ft_is_flag(char c)
{
	//printf("hiit %d", c);
	if (c == '#' || c == '0' || c == '-' || c == '+' || c == ' ')
		return (1);
	else
		return (0);
}
int	ft_is_conv_char(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 'f')
		return (1);
	else
		return (0);
}
char	*create_struct(char *format)
{
	int i;
	int j;
	format_struct new;

	i = 0;
	j = 0;
	new.width = 0;
	new.precision = 0;
	new.f_hash = 0;
	new.f_zero = 0;
	new.f_minus = 0;
	new.f_plus = 0;
	new.f_space = 0;
	while (format[i] != '\0')
	{
		if (ft_is_flag(format[i]) == 1)
			ft_set_flag(format[i], &new);
		else if (ft_isdigit(format[i]) == 1 && format[i] != '0')
		{
			while(ft_isdigit(format[i]) == 1 && format[i] != '\0')
			{
				new.width = new.width * 10 + format[i] - 48;
				i++;
		 			if (format[i] == '.')
					{
						i++;
							while(ft_isdigit(format[i]) == 1 && format[i] != '\0')
							{			
								new.precision = new.precision * 10 + format[i] - 48;
								i++;
							}
					}			
			}
		}
		while (ft_isalpha(format[i]) && format[i] != '.' && ft_is_conv_char(format[i]) != 1 && j < 2 && format[i] != '\0')
		{
			new.length[j] = format[i];
			j++;
			i++;
		}
		i++;
	}
	printf("%d\n %d\n %d\n %d\n %d\n", new.f_hash, new.f_zero, new.f_minus, new.f_plus, new.f_space);
	printf("%d\n %d\n %s\n", new.width, new.precision, new.length);
	return (&format[i]);
}

int	ft_printf(int a, ...)
{
	va_list ap;
	va_list test;
	int i;

	i = 0;
	va_start(ap, a);
	while(i < a)
	{
		va_copy(test, ap);
		printf("%d\n", va_arg(ap, int));
		i++;
	}
	i = 0;
	while (i < a)
	{
		printf("%d\n", va_arg(ap, int));
		i++;
	}
	return (i);
}

int	main(void)
{
	//int done;
	//int i = 10;

	//char *str = "japp\0";
	//done = ft_printf(3, 10, 4, 7);
	create_struct("%#+-0305.81llc");

}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrankul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:07:26 by vgrankul          #+#    #+#             */
/*   Updated: 2020/01/20 14:27:13 by vgrankul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>
void ft_set_to_zero (format_struct *new)
{
	new->width = 0;
	new->precision = 0;
	new->f_hash = 0;
	new->f_zero = 0;
	new->f_minus = 0;
	new->f_plus = 0;
	new->f_space = 0;
}

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
char *ft_set_length(char *format, format_struct *new)
{
	int j;

	j = 0;
	while (ft_isalpha(*format) && *format != '.' && ft_is_conv_char(*format) != 1 && j < 2 && *format != '\0')
	{
		new->length[j] = *format;
		j++;
		format++;
	}
	new->length[j] = '\0';
	return(format);
}

char	*create_struct(char *format)
{
	//int i;
	int j;
	format_struct new;

	//i = 0;
	j = 0;
	ft_set_to_zero(&new);
	while (*format != '\0' && ft_is_conv_char(*format) != 1)
	{
		if (ft_is_flag(*format) == 1)
			ft_set_flag(*format, &new);
		else if (ft_isdigit(*format) == 1 && *format != '0')
		{
			while(ft_isdigit(*format) == 1 && *format != '\0')
			{
				new.width = new.width * 10 + *format - 48;
				format++;
		 			if (*format == '.')
					{
						format++;
							while(ft_isdigit(*format) == 1 && *format != '\0')
							{
								new.precision = new.precision * 10 + *format - 48;
								format++;
							}
					}
			}
		}
	if (ft_isalpha(*format) && *format != '.')
		ft_set_length(format, &new);
		format++;
	}
	new.conv_char = *format;
//	printf("string %s\n", new.length);
	printf("%d\n %d\n %d\n %d\n %d\n", new.f_hash, new.f_zero, new.f_minus, new.f_plus, new.f_space);
	printf("%d\n %d\n %s\n %c\n", new.width, new.precision, new.length, new.conv_char);
	return (format);
}
int	ft_create_string(const char *format, va_list ap)
{
	ap = 0;
	while(ft_is_conv_char(*format) == 1)
	{
		format++;
	}
	printf("%s\n", format);
	return (0);
}
int ft_vfprintf(const char *format, va_list ap)
{
	int done;

	done = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			done = done + ft_create_string(format, ap);
			//printf("%s\n", format);
		}
		//write(1, *format, 1);
		done++;
		format++;
	}
	return (done);
}

int	ft_printf(const char *format, ...)
{
	va_list ap;
	int done;

	va_start(ap, format);
	done = ft_vfprintf(format, ap);
	va_end(ap);
	return (done);
}

int	main(void)
{
	//int done;
	//int i = 10;

	//char *str = "japp\0";
	//done = ft_printf(3, 10, 4, 7);
	create_struct("%+-0#306.8hhdtest2");

}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrankul <vgrankul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:07:26 by vgrankul          #+#    #+#             */
/*   Updated: 2020/02/06 16:45:01 by vgrankul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_set_length(const char *format, t_format_struct *new)
{
	int  j;
	int i;

	j = 0;
	i = 0;
	while (ft_isalpha(format[i]) && format[i] != '.' && ft_is_conv_char(format[i]) != 1 && j < 2 && format[i] != '\0')
	{
		new->length[j] = format[i];
		j++;
		i++;
	}
	new->length[j] = '\0';
	// needs to be - 1 since it counts one too many when it while loops 0, 1, stops at 2.
	return (i -1);
}

int 	create_struct(const char *format, va_list ap)
{
	int i;
	int j;
	t_format_struct new;

	i = 0;
	j = 0;
	ft_set_to_zero(&new);
	while (format[i] != '\0' && ft_is_conv_char(format[i]) != 1)
	{
		if (ft_is_flag(format[i]) == 1)
			ft_set_flag(format[i], &new);
		if (ft_isdigit(format[i]) == 1 && format[i] != '0')
		{
			while(ft_isdigit(format[i]) == 1 && format[i] != '\0')
				new.width = new.width * 10 + format[i++] - 48;
		}
		 			if (format[i] == '.')
					{
						i++;
							if (ft_isdigit(format[i]) != 1 || format[i] == '0')
								new.precision = -1;
							while(ft_isdigit(format[i]) == 1 && format[i] != '\0')
								new.precision = new.precision * 10 + format[i++] - 48;
					}
	if (ft_isalpha(format[i]) && format[i] != '.' && ft_is_conv_char(format[i]) != 1)
		i = i + ft_set_length(&format[i], &new);
	if (ft_is_conv_char(format[i]) == 1 || format[i] == '%') // add if conv_char == %, break and add as conv_char, remove ft_is_conv in the outer loop or set if format[i] == % break. 
		break;
	i++;
}
	new.conv_char = format[i];
	//printf("char %c\n", format[i]);
	ft_check_conv_char(&new, ap);
//	printf("string %d\n", new.f_minus);
//	printf("%d\n %d\n %d\n %d\n %d\n", new.f_hash, new.f_zero, new.f_minus, new.f_plus, new.f_space);
//	printf("%d\n %d\n %s\n %c\n", new.width, new.precision, new.length, new.conv_char);
	return (0);
	//should return the amount of chars printed.
}

int ft_vfprintf(const char *format, va_list ap)
{
	int done;
	int i;

	done = 0;
	i = 0;
	while (format[i] != '\0')
	{
//	printf("%s\n", &format[i]);

		if (format[i] == '%')
		{
		//	printf("hiid");
		//	printf("%s\n", &format[i]);
		i++;
			done = done + create_struct(&format[i], ap);
			// print the string?
			i = i + format_strlen(&format[i]);
		//	printf("i = %d\n", i);
		}
		ft_putchar(format[i]);
		done++;
		i++;
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
	//char *s = "string";
	int i = 1456;
	//float c = 12.12;

	//char *str = "japp\0";
	//done = ft_printf(3, 10, 4,i 7);
	//system("leaks a.out");
	ft_printf("test:%#8.5xera test\n", i);
	printf("test:%#8.5xera test", i);
}

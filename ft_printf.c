/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrankul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:07:26 by vgrankul          #+#    #+#             */
/*   Updated: 2020/01/23 15:39:22 by vgrankul         ###   ########.fr       */
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
int ft_set_length(const char *format, format_struct *new)
{
	int j;
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
void	ft_va_arg_int(format_struct *new, va_list ap)
{
	long long n;
	int a;

	if(new->length[0] == '\0')
		n = va_arg(ap, int);
	else if(new->length[0] == 'l' && new->length[1] == 'l')
		n = va_arg(ap, long long);
	else if(new->length[0] == 'l' && new->length[1] == '\0')
		n = va_arg(ap, long);
	else if(new->length[0] == 'h' && new->length[1] == 'h')
	{
		a = va_arg(ap, int);
		n = (char)a;
	}
	else if (new->length[0] == 'h' && new->length[1] == '\0')
	{
		a = va_arg(ap, int);
		n = (short)a;
	}
}

void	ft_va_arg_octal(format_struct *new, va_list ap)
{
	long long n;
	int a;

	if(new->length[0] == '\0')
		n = va_arg(ap, int);
	else if(new->length[0] == 'l' && new->length[1] == 'l')
		n = va_arg(ap, long long);
	else if(new->length[0] == 'l' && new->length[1] == '\0')
		n = va_arg(ap, long);
	else if(new->length[0] == 'h' && new->length[1] == 'h')
	{
		a = va_arg(ap, unsigned int);
		n = (unsigned char)a;
	}
	else if (new->length[0] == 'h' && new->length[1] == '\0')
	{
		a = va_arg(ap, unsigned int);
		n = (unsigned short)a;
	}
}

void	ft_va_arg_unsigned_int(format_struct *new, va_list ap)
{
	unsigned long long n; 
	unsigned int a;

	if(new->length[0] == '\0')
		n = va_arg(ap, unsigned int);
	else if(new->length[0] == 'l' && new->length[1] == 'l')
		n = va_arg(ap, unsigned long long);
	else if(new->length[0] == 'l' && new->length[1] == '\0')
		n = va_arg(ap, unsigned long);
	else if(new->length[0] == 'h' && new->length[1] == 'h')
	{
		a = va_arg(ap, unsigned int);
		n = (unsigned char)a;
	}
	else if (new->length[0] == 'h' && new->length[1] == '\0')
	{
		a = va_arg(ap, unsigned int);
		n = (unsigned short)a;
	}
}

void	ft_va_arg_hex(format_struct *new, va_list ap)
{
	unsigned long long n; 
	unsigned int a;

	if(new->length[0] == '\0')
		n = va_arg(ap, unsigned int);
	else if(new->length[0] == 'l' && new->length[1] == 'l')
		n = va_arg(ap, unsigned long long);
	else if(new->length[0] == 'l' && new->length[1] == '\0')
		n = va_arg(ap, unsigned long);
	else if(new->length[0] == 'h' && new->length[1] == 'h')
	{
		a = va_arg(ap, unsigned int);
		n = (unsigned char)a;
	}
	else if (new->length[0] == 'h' && new->length[1] == '\0')
	{
		a = va_arg(ap, unsigned int);
		n = (unsigned short)a;
	}

}
void	ft_va_arg_float(format_struct *new, va_list ap)
{
	long double n;

	if(new->length[0] == '\0' || new->length[0] == 'l')
		n = va_arg(ap, double);
	else if (new->length[0] == 'L')
		n = va_arg(ap, long double);
}
void	ft_va_arg_char(format_struct *new, va_list ap)
{
	int n;

	n = va_arg(ap, int);
	n = (char)n;
}

void	ft_va_arg_string(format_struct *new, va_list ap)
{
	char *str;

	str = va_arg(ap, char*);
}

void	ft_va_arg_mem(format_struct *new, va_list ap)
{
	char *str;

	str = va_arg(ap, char*);
}

void	ft_check_conv_char(format_struct *new, va_list ap)
{
	if (new->conv_char == 'd' || new->conv_char == 'i')
		ft_va_arg_int(new, ap);
	else if (new->conv_char == 'o')
		ft_va_arg_octal(new, ap);
	else if (new->conv_char == 'u')
		ft_va_arg_unsigned_int(new, ap);
	else if (new->conv_char == 'x' || new->conv_char == 'X')
		ft_va_arg_hex(new, ap);
	else if (new->conv_char == 'f')
		ft_va_arg_float(new, ap);
	else if (new->conv_char == 'c')
		ft_va_arg_char(new, ap);
	else if (new->conv_char == 's')
		ft_va_arg_string(new, ap);
	else if((new->conv_char == 'p')
		ft_va_arg_mem(new, ap);
)


}

int 	create_struct(const char *format, va_list ap)
{
	int i;
	int j;
	format_struct new;

	i = 0;
	j = 0;
	ft_set_to_zero(&new);
	while (format[i] != '\0' && ft_is_conv_char(format[i]) != 1)
	{
		if (ft_is_flag(format[i]) == 1)
			ft_set_flag(format[i], &new);
		else if (ft_isdigit(format[i]) == 1 && format[i] != '0')
		{
			while(ft_isdigit(format[i]) == 1 && format[i] != '\0')
			{
				new.width = new.width * 10 + format[i++] - 48;
		 			if (format[i] == '.')
					{
						i++;
							while(ft_isdigit(format[i]) == 1 && format[i] != '\0')
								new.precision = new.precision * 10 + format[i++] - 48;
					}
			}
		}
	if (ft_isalpha(format[i]) && format[i] != '.' && ft_is_conv_char(format[i]) != 1)
		i = i + ft_set_length(&format[i], &new);
	i++;
	}
	new.conv_char = format[i];
	ft_check_conv_char(&new, ap);
	//printf("string %s\n", new.length);
	printf("%d\n %d\n %d\n %d\n %d\n", new.f_hash, new.f_zero, new.f_minus, new.f_plus, new.f_space);
	printf("%d\n %d\n %s\n %c\n", new.width, new.precision, new.length, new.conv_char);
	return (0);
	//should return the amount of chars printed.
}
int	format_strlen(const char *format)
{
	int i;

	i = 0;
	while (format[i] != '\0' && ft_is_conv_char(format[i]) != 1)
	{
		i++;
	}
	return (i + 1);
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
			done = done + create_struct(&format[i], ap);
			// print the string?
			i = i + format_strlen(&format[i]);
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
	long long i = 1111144;

	//char *str = "japp\0";
	//done = ft_printf(3, 10, 4, 7);
	ft_printf("test: %hhdcera test %ld", i, i);

}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrankul <vgrankul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:07:26 by vgrankul          #+#    #+#             */
/*   Updated: 2020/02/13 14:38:21 by vgrankul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_set_length(const char *format, t_format_struct *new)
{
	int  j;
	int i;

	j = 0;
	i = 0;
	while (ft_isalpha(format[i]) == 1 && format[i] != '.' && ft_is_conv_char(format[i]) != 1 && j < 2 && format[i] != '\0')
	{		
		new->length[j] = format[i];
		j++;
		i++;
	}
	new->length[j] = '\0';
	// needs to be - 1 since it counts one too many when it while loops 0, 1, stops at 2.
	return (i);
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
						new.prec = 1;
						i++;
							//if (ft_isdigit(format[i]) != 1 || format[i] == '0')
							//	new.precision = -1;
							while(ft_isdigit(format[i]) == 1 && format[i] != '\0')
								new.precision = new.precision * 10 + format[i++] - 48;
					}
	if (ft_isalpha(format[i]) == 1 && format[i] != '.' && ft_is_conv_char(format[i]) != 1)
		i = i + ft_set_length(&format[i], &new);
	if (ft_is_conv_char(format[i]) == 1 || format[i] == '%')
	// add if conv_char == %, break and add as conv_char, remove ft_is_conv in the outer loop or set if format[i] == % break. 
		break;
	i++;
}	
	if(ft_is_conv_char(format[i]) == 1 || format[i] == '%')
		new.conv_char = format[i];
	else
		return(0);
	//printf("char %c\n", format[i]);

	//printf("pre%d\n", new.f_zero);
//	printf("%d\n %d\n %d\n %d\n %d\n", new.f_hash, new.f_zero, new.f_minus, new.f_plus, new.f_space);
//	printf("%d\n %d\n %s\n %c\n", new.width, new.precision, new.length, new.conv_char);
	//should return the amount of chars printed.
	return(ft_check_conv_char(&new, ap));
}

int ft_vfprintf(const char *format, va_list ap)
{
	int done;
	int i;

	done = 0;
	i = 0;
	//printf("formatstr %s\n", format);
	while (format[i] != '\0')
	{
		//printf("hiid");
		if (format[i] == '%')
		{
			//printf("ok");
		//	printf("hiid");
		//	printf("%s\n", &format[i]);
		i++;
			done = done + create_struct(&format[i], ap);
		//	printf("done %d\n i = %d\n", done, i);
			// print the string?
			//while (format[i] != '\0' && ft_is_conv_char(format[i]) != 1)
			//	i++;
			//i = i + 1;
			i = i + format_strlen(&format[i]) - 1;
		//	printf("form %d\n", format_strlen(&format[i]));
		//	printf("i = %d\n", i);
		}
		else
		{
			ft_putchar(format[i]);
			done++;
		}
		i++;
		//printf("i inne %d\n", i);
	}
	//printf("done %d\n i = %d\n", done, i);
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

/*int	main(void)
{
	//int done;
//	char *s = "string";
//int i = 42;
	//float c = 12.12;
	//int i;

	//char *str = "japp\0";
	//done = ft_printf(3, 10, 4,i 7);
	//system("leaks a.out");
	//ft_printf("%c", 't');
	//ft_printf("%s", "string");
	ft_printf("%f\n", 10.0894255);
	printf("%f", 10.0894255);
	//printf("%lld", ft_power_of(10, 19));
	//printf("\n");
	//printf("%lld\n", ft_power_of(10, 12));
	//printf("111%s333%.2s555", "222", "444");
	//system("leaks a.out");
	//printf("%d", printf("%d", 42));
}*/
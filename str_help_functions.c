/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_help_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrankul <vgrankul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:07:26 by vgrankul          #+#    #+#             */
/*   Updated: 2020/02/06 15:11:21 by vgrankul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_to_dot(char *str)
{
	int counter;

	counter = 0;
	while(*str != '\0' && *str != '.')
	{
		str++;
		counter++;
	}
	return (counter + 1);
}
char *ft_copy_string(char *str, int len)
{
	char *str1;
	int i;
	char *tmp;

	tmp = str;
	i = 0;
	str1 = (char*)malloc(len *sizeof(char) + 1);
	while(i < len && str[i] != '\0')
	{
		str1[i] = str[i];
		i++;
	}
	str1[i] = '\0';
	free(tmp);
	return(str1);
}

char *ft_string_tolower(char *str)
{
	int i;
	
	i = 0;
	while(str[i] != '\0')
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}

int	format_strlen(const char *format)
{
	int i;

	i = 0;
	while (format[i] != '\0' && ft_is_conv_char(format[i]) != 1 && format[i] != '%')
	{  
		i++;
	}
	return (i + 1);
}
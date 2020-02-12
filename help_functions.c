
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrankul <vgrankul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:07:26 by vgrankul          #+#    #+#             */
/*   Updated: 2020/02/06 14:08:09 by vgrankul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_add_ox(char *str, t_format_struct *new)
{
	char *str1;
	char *str2;

	str2 = str;
	if(!(str1 = (char*)malloc(3 * sizeof(char))))
		return (NULL);
	if (new->conv_char == 'X')
	{
		str1[0] = '0';
		str1[1] = 'X';
		str1[2] = '\0';
	}
	else
	{
		str1[0] = '0';
		str1[1] = 'x';
		str1[2] = '\0';
	}
	str = ft_strjoin(str1, str);
	free(str1);
	free(str2);
	return(str);
}
char *ft_set_zero(char *str, t_format_struct *new)
{
	char *str2;
	int len;
	int preclen;
	int i;
	int j;

	i = 0;
	j = 0;
	if (str[0] == '-' || str[0] == '+')
		new->precision = new->precision + 1;
	len = (new->precision - ft_strlen(str)) + ft_strlen(str);
	preclen = new->precision - ft_strlen(str);
	if(!(str2 = (char*)malloc(len * sizeof(char) + 1)))
		return (NULL);
	while (j < len)
	{	
		if (preclen == 0)
			str2[j] = str[i++];
		if (str[i] == '-' || str[i] == '+')
			str2[j++] = str[i++];
		if (preclen > 0)
		{
			str2[j] = '0';
			preclen--;
		}
		j++;
	}
	str2[j] = '\0';
	return (str2);
}

char *ft_set_space(char *str, t_format_struct *new, char sign)
{
	char *str2;
	int len;
	int i;
	int j;
	int widthlen;

	i = 0;
	j = 0;
	len = (new->width - ft_strlen(str)) + ft_strlen(str);
	widthlen = new->width - ft_strlen(str);
	if(!(str2 = (char*)malloc(len * sizeof(char) + 1)))
		return (NULL);
	if (new->f_minus == 1 && new->f_zero != 1) 
	{
		while (str[i] != '\0')
		{
			str2[j] = str[i];
			i++;
			j++;
		}
		while(widthlen > 0)
		{
			str2[j] = sign;
			widthlen--;
			j++;
		}
	}
	else
	{
		if ((new->conv_char == 'x' || new->conv_char == 'X') && new->f_hash == 1 && sign == '0')
		{
			while(j < 2)
				str2[j++] = str[i++];
		}
		while (j < len)
		{
			if (widthlen == 0)
				str2[j] = str[i++];
			if (str[i] == '-' && sign == '0' && new->conv_char == 'f')
				str2[j++] = str[i++];
			else if ((str[i] == '-' || str[i] == '+'  || str[i]== ' ') && sign == '0')
				str2[j++] = str[i++];
			if (widthlen > 0)
			{
				str2[j] = sign;
				widthlen--;
			}
			j++;
		}
		str2[j] = '\0';
	}
	str2[j] = '\0';
	return(str2);

}
char *ft_set_sign(char *str, char sign)
{
	char *str1;
	//har *str2;

	//str2 = str;
	str1 = (char*)malloc(2 * sizeof(char));
	if (str[0] == '-')
		return (str);
	str1[0] = sign;
	str1[1] = '\0';
	str = ft_strjoin(str1, str);
	free(str1);
	//free(str2);
	return (str);
	
}
char *ft_add_zero(char *str, int len)
{
	char *str2;
	int strlen;
	int dotlen;
	int i;
	int j;

	i = 0;
	j = 0;
	strlen = ft_strlen(str) + len;
	dotlen = count_to_dot(str);
	if(!(str2 = (char*)malloc(strlen * sizeof(char) + 1)))
		return (NULL);
	while (str[i] != '\0')
	{
		if (dotlen > 0)
		{
			str2[j] = str[i++];
			dotlen--;
		}
		else if (len > 0 && dotlen == 0)
		{
			str2[j] = '0';
			len--;
		}
		else if (dotlen == 0 && len == 0)
		{
			str2[j] = str[i];
			i++;
		}
		j++;
	}
	str2[j] = '\0';
	return (str2);
}
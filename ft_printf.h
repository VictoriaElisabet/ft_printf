/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrankul <vgrankul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:26:47 by vgrankul          #+#    #+#             */
/*   Updated: 2020/02/11 13:13:03 by vgrankul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
#include <stdio.h>
#include <stdarg.h>

typedef struct	s_format
{
	int		f_hash;
	int		f_zero;
	int		f_minus;
	int		f_plus;
	int		f_space;
	int		width;
	int		prec;
	int		precision;
	char	length[3];
	char	conv_char;

}				t_format_struct;


void			ft_set_to_zero (t_format_struct *new);
void			ft_set_flag(char c, t_format_struct *new);


int				ft_is_flag(char c);
int				ft_is_conv_char(char c);
int				count_to_dot(char *str);
int				format_strlen(const char *format);
int				ft_set_length(const char *format, t_format_struct *new);
int				create_struct(const char *format, va_list ap);
int				ft_vfprintf(const char *format, va_list ap);
int				ft_printf(const char *format, ...);
int				ft_check_flags_diouxx(char *str, t_format_struct *new);
int				ft_check_flags_float(char *str, t_format_struct *new);
int				ft_check_flags_char(char *str, t_format_struct *new);
int				ft_check_flags_string(char *str, t_format_struct *new);
int				ft_va_arg_float(t_format_struct *new, va_list ap);
int				ft_va_arg_char(t_format_struct *new, va_list ap);
int				ft_va_arg_string(t_format_struct *new, va_list ap);
int				ft_va_arg_mem(t_format_struct *new, va_list ap);
int				ft_va_arg_int(t_format_struct *new, va_list ap);
int				ft_va_arg_octal(t_format_struct *new, va_list ap);
int				ft_va_arg_unsigned_int(t_format_struct *new, va_list ap);
int				ft_va_arg_hex(t_format_struct *new, va_list ap);
int				ft_check_conv_char(t_format_struct *new, va_list ap);

char			*ft_add_ox(char *str, t_format_struct *new);
char			*ft_set_zero(char *str, t_format_struct *new);
char			*ft_set_space(char *str, t_format_struct *new, char sign);
char			*ft_set_sign(char *str, char sign);
char			*ft_copy_string(char *str, int len);
char			*ft_string_tolower(char *str);
char			*ft_add_zero(char *str, int len);
char			*ft_copy_string_float(char *str, t_format_struct *new);
char			*ft_itoa_double(long double n, int precision, t_format_struct *new);

#endif

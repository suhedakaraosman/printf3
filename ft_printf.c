/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaraosm <skaraosm@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:32:19 by skaraosm          #+#    #+#             */
/*   Updated: 2025/07/10 18:36:08 by skaraosm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>

static int	ft_is_conversion_specifier(char c)
{
	return (c == 'd' || c == 'i' || c == 's' || c == 'c' || c == 'p' || \
			c == 'x' || c == 'X' || c == 'u');
}

static int	ft_handle_conversion(va_list args, char fmt)
{
	int	count;

	count = 0;
	if (fmt == 'd' || fmt == 'i')
		count = ft_print_nbr(va_arg(args, int));
	else if (fmt == 's')
		count = ft_print_str(va_arg(args, char *));
	else if (fmt == 'c')
		count = ft_print_chr(va_arg(args, int));
	else if (fmt == 'p')
		count = ft_print_ptr(va_arg(args, void *));
	else if (fmt == 'x')
		count = ft_print_hex_lower(va_arg(args, unsigned int));
	else if (fmt == 'X')
		count = ft_print_hex_upper(va_arg(args, unsigned int));
	else if (fmt == 'u')
		count = ft_print_unsigned(va_arg(args, unsigned int));
	return (count);
}

static int	ft_process_percent(va_list args, const char *format, int *i)
{
	int	char_count;

	(*i)++;
	if (!format[*i])
		return (write(1, "%", 1));
	else if (format[*i] == '%')
		return (ft_print_percent());
	else if (ft_is_conversion_specifier(format[*i]))
	{
		char_count = ft_handle_conversion(args, format[*i]);
		if (char_count == -1)
			return (-1);
	}
	else
	{
		char_count = write(1, "%", 1);
		if (char_count == -1)
			return (-1);
		char_count += write(1, &format[*i], 1);
	}
	return (char_count);
}

static int	ft_process_char(va_list args, const char *format, int *i_ptr)
{
	int	res;

	if (format[*i_ptr] == '%')
	{
		res = ft_process_percent(args, format, i_ptr);
		(*i_ptr)++;
	}
	else
	{
		res = write(1, &format[*i_ptr], 1);
		(*i_ptr)++;
	}
	return (res);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;
	int		res;

	i = 0;
	len = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		res = ft_process_char(args, format, &i);
		if (res == -1)
		{
			va_end(args);
			return (-1);
		}
		len += res;
	}
	va_end(args);
	return (len);
}

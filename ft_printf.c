/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaraosm <skaraosm@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:32:19 by skaraosm          #+#    #+#             */
/*   Updated: 2025/06/30 18:32:23 by skaraosm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>

static int	ft_handle_conversion(va_list args, char fmt)
{
	if (fmt == 'd' || fmt == 'i')
		return (ft_print_nbr(va_arg(args, int)));
	else if (fmt == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (fmt == 'c')
		return (ft_print_chr(va_arg(args, int)));
	else if (fmt == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	else if (fmt == 'x')
		return (ft_print_hex_lower(va_arg(args, unsigned int)));
	else if (fmt == 'X')
		return (ft_print_hex_upper(va_arg(args, unsigned int)));
	else if (fmt == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (fmt == '%')
		return (ft_print_percent());
	return (0);
}
#include <stdio.h>
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			len += ft_handle_conversion(args, format[i]);
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}

	
// va_start(args, format); Neden Böyle bir şey var

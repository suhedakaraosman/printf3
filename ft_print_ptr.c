/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaraosm <skaraosm@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:32:19 by skaraosm          #+#    #+#             */
/*   Updated: 2025/07/02 14:32:11 by skaraosm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_print_ptr(void *ptr)
{
	int		total_len;
	int		ret;

	if (ptr == NULL)
	{
		ret = write(1, "(nil)", 5);
		if (ret == -1)
			return (-1);
		return (ret);
	}
	ret = write(1, "0x", 2);
	if (ret == -1)
		return (-1);
	total_len = ret;
	ret = ft_print_hex_lower((unsigned long)ptr);
	if (ret == -1)
		return (-1);
	total_len += ret;
	return (total_len);
}

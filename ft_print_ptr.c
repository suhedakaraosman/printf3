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

#include <unistd.h>

int	ft_print_ptr(void *ptr)
{
	char			*hex;
	unsigned long	ret;
	char			buf[16];
	int				i;
	int				res;

	if (ptr == NULL) 
	{
		if (write(1, "(nil)", 5) < 0)
			return (-1);
		return (5);
	}
	ret = (unsigned long)ptr;
	hex = "0123456789abcdef";
	if (write(1, "0x", 2) < 0)
		return (-1);
	res = 2;
	i = 0;
	while (ret > 0)
	{
		buf[i++] = hex[ret % 16];
		ret /= 16;
	}
	while (i-- > 0)
	{
		if (write(1, &buf[i], 1) < 0)
			return (-1);
		res++;
	}
	return (res);
}

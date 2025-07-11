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

static int	ft_put_hex_ptr(unsigned long n)
{
	char	buf[17];
	char	*hex;
	int		i;
	int		res;

	hex = "0123456789abcdef";
	i = 0;
	while (n > 0)
	{
		buf[i++] = hex[n % 16];
		n /= 16;
	}
	res = 0;
	while (i--)
	{
		if (write(1, &buf[i], 1) == -1)
			return (-1);
		res++;
	}
	return (res);
}

int	ft_print_ptr(void *ptr)
{
	int	res;
	int	tmp;

	if (!ptr)
		return (write(1, "(nil)", 5));
	if (write(1, "0x", 2) == -1)
		return (-1);
	res = 2;
	tmp = ft_put_hex_ptr((unsigned long)ptr);
	if (tmp == -1)
		return (-1);
	return (res + tmp);
}

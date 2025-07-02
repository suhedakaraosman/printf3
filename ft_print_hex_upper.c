/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_upper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaraosm <skaraosm@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:31:49 by skaraosm          #+#    #+#             */
/*   Updated: 2025/07/02 13:59:18 by skaraosm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_print_hex_upper(unsigned long i)
{
	char	hex_char;
	int		total_len;
	int		recursive_len;

	if (i == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	total_len = 0;
	if (i >= 16)
	{
		recursive_len = ft_print_hex_upper(i / 16);
		if (recursive_len == -1)
			return (-1);
		total_len += recursive_len;
	}
	if ((i % 16) < 10)
		hex_char = '0' + (i % 16);
	else
		hex_char = 'A' + ((i % 16) - 10);
	if (write(1, &hex_char, 1) < 0)
		return (-1);
	return (total_len + 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_lower.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaraosm <skaraosm@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:32:19 by skaraosm          #+#    #+#             */
/*   Updated: 2025/07/02 14:30:22 by skaraosm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_print_hex_lower(unsigned long num)
{
	char	hex_char;
	int		total_len;
	int		recursive_len;

	if (num == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	total_len = 0;
	if (num >= 16)
	{
		recursive_len = ft_print_hex_lower(num / 16);
		if (recursive_len == -1)
			return (-1);
		total_len += recursive_len;
	}
	if ((num % 16) < 10)
		hex_char = '0' + (num % 16);
	else
		hex_char = 'a' + ((num % 16) - 10);
	if (write(1, &hex_char, 1) == -1)
		return (-1);
	return (total_len + 1);
}

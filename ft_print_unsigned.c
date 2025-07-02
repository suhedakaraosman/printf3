/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaraosm <skaraosm@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:33:58 by skaraosm          #+#    #+#             */
/*   Updated: 2025/07/02 14:30:52 by skaraosm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_print_unsigned(unsigned int nbr)
{
	char	c;
	int		len;
	int		ret;

	if (nbr == 0)
	{
		if (write(1, "0", 1) < 0)
			return (-1);
		return (1);
	}
	len = 0;
	if (nbr >= 10)
	{
		ret = ft_print_unsigned(nbr / 10);
		if (ret < 0)
			return (-1);
		len += ret;
	}
	c = '0' + (nbr % 10);
	if (write(1, &c, 1) < 0)
		return (-1);
	return (len + 1);
}

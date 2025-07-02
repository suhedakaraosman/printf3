/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaraosm <skaraosm@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:32:19 by skaraosm          #+#    #+#             */
/*   Updated: 2025/06/30 18:32:23 by skaraosm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_print_nbr(int n)
{
	int		res;
	int		ret;
	char	c;

	res = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		res++;
		n = -n;
	}
	if (n >= 10)
	{
		ret = ft_print_nbr(n / 10);
		if (ret == -1)
			return (-1);
		res += ret;
	}
	c = '0' + (n % 10);
	if (write(1, &c, 1) == -1)
		return (-1);
	return (res + 1);
}

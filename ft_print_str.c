/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaraosm <skaraosm@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:32:19 by skaraosm          #+#    #+#             */
/*   Updated: 2025/06/30 18:32:23 by skaraosm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_print_str(char *s)
{
	int	len;
	int	res;

	if (!s)
		s = "(null)";
	len = 0;
	while (s[len])
		len++;
	res = write(1, s, len);
	if (res == -1)
		return (-1);
	return (res);
}

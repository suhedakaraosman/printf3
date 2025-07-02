/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaraosm <skaraosm@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:35:08 by skaraosm          #+#    #+#             */
/*   Updated: 2025/07/02 15:48:57 by skaraosm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_print_chr(int c);
int		ft_print_hex_lower(unsigned long num);
int		ft_print_hex_upper(unsigned long num);
int		ft_print_nbr(int n);
int		ft_print_percent(void);
int		ft_print_ptr(void *ptr);
int		ft_print_str(char *s);
int		ft_print_unsigned(unsigned int nbr);

#endif

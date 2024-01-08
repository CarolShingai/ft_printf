/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:23:52 by cshingai          #+#    #+#             */
/*   Updated: 2024/01/08 20:23:33 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <string.h>
#include <unistd.h>

#include <stdio.h>

int	ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_printf(const char *str, ...);
int	print_format(const char *str, va_list args, int idx);
int	ft_strlen(const char *str);
int	ft_putstr(char *s);
int	ft_putnbr_hex(unsigned int nbr, int type);
int	ft_putnbr_dec(unsigned int n);
int	ft_put_pointer(unsigned long nbr, int type);

#endif
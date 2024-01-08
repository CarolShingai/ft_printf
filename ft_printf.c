/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:39:07 by cshingai          #+#    #+#             */
/*   Updated: 2024/01/06 15:35:31 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(const char *str, va_list args, int idx)
{
	int result;

	result = 0;
	if (str[idx] == 'c')
		result = ft_putchar(va_arg(args, int));
	else if (str[idx] == 'd')
		result = ft_putnbr(va_arg(args, int));
	else if (str[idx] == 's')
		result = ft_putstr(va_arg(args, char *));
	return (result);
}



int	ft_printf(const char *str, ...)
{
	int		i;
	int 	num_char;
	va_list args;
	va_start(args, str);
	
	i = 0;
	num_char = 0;
	while(str[i])
	{
		if(str[i] == '%' && str[i + 1])
		{
			num_char += print_format(str, args, i + 1);
			i++;
		}
		else
			num_char += ft_putchar(str[i]);
		i++;	
	}
	va_end(args);
	return (num_char);
}

int	main(void)
{
	char x[] = "foi?";
	
	ft_printf("ft_printf:%c%d%s\n", 'a', 15, x);
	printf("printf:%c%d%s\n", 'a', 15, x);
	printf("sem argumentos:");
	// printf();
    return 0;
}



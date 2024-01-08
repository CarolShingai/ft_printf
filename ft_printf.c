/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:39:07 by cshingai          #+#    #+#             */
/*   Updated: 2024/01/08 20:35:23 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(const char *str, va_list args, int idx)
{
	unsigned long	pointer;

	if (str[idx] == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (str[idx] == 'd' || str[idx] == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (str[idx] == 'u')
		return (ft_putnbr_dec(va_arg(args, int)));
	else if (str[idx] == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (str[idx] == 'x')
		return (ft_putnbr_hex(va_arg(args, unsigned int), 0));
	else if (str[idx] == 'X')
		return (ft_putnbr_hex(va_arg(args, unsigned int), 1));
	else if (str[idx] == 'p')
	{
		pointer = va_arg(args, unsigned long);
		if (pointer == 0)
			return (write(1, "(nil)", 5));
		return (write(1, "0x", 2) + ft_put_pointer(pointer, 0));
	}
	else if (str[idx] == '%')
		return (ft_putchar('%'));
	return (0);
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

// int	main(void)
// {
// 	char x[] = "foi?";
// 	int h = 255;
// 	int count_original, count_mine;

// 	count_mine = ft_printf("%c%d%s\n", 'a', 15, x);
// 	count_original = printf("%c%d%s\n", 'a', 15, x);
// 	printf("original %i - minha - %i\n", count_original, count_mine);


// 	count_mine = ft_printf("sem argumentos: %s\n", (char *) 0);
// 	count_original = printf("sem argumentos: %s\n", (char *) 0);
// 	printf("original %i - minha - %i\n", count_original, count_mine);


// 	count_mine = ft_printf("hex: %X\n", h);
// 	count_original = printf("hex: %X\n", h);
// 	printf("original %i - minha - %i\n", count_original, count_mine);

// 	count_mine = ft_printf("dec: %u\n", 48);
// 	count_original = printf("dec: %u\n", 48);
// 	printf("original %i - minha - %i\n", count_original, count_mine);

// 	count_mine = ft_printf("perc: %%\n");
// 	count_original = printf("perc: %%\n");
// 	printf("original %i - minha - %i\n", count_original, count_mine);

// 	return 0;
// }

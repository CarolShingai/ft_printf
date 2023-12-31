/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:39:07 by cshingai          #+#    #+#             */
/*   Updated: 2023/12/30 19:29:07 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <string.h>

void	ft_printf(char *placeholders, ...);

int	main(void)
{
	ft_printf("fddf", 1.2, 51, 3, 12.5);
}

void ft_printf(char *placeholders, ...)
{
	int		i;
	int 	num_args;
	va_list args;
	va_start(args, placeholders);

	i = -1;
	num_args = strlen(placeholders);
	while (i++ <num_args)
	{
		if(placeholders[i] == 'd')
		{
			int x;
			
			x = va_arg(args, int);
			printf("%d\n", x);
		}
		else if(placeholders[i] == 'f')
		{
			double x;
			
			x = va_arg(args, double);
			printf("%f\n", x);
		}	
	}
	va_end(args);
}




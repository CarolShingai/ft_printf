/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:39:07 by cshingai          #+#    #+#             */
/*   Updated: 2023/12/15 18:39:02 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int max(int a, ...){

}

void print(int num_args, ...)
{
	int	num_args = strlen(num_args);
	int	i;

	va_list	args;
	va_start(args, num_args);

	while (i = 0 && i < num_args)
	{
		if (num_args[i] == 'd')
		{
			int	x = va_args(args);
		}
	}
}
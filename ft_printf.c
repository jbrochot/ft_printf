/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 09:05:54 by ezonda            #+#    #+#             */
/*   Updated: 2019/01/17 17:30:18 by jebrocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_struct	stru;
	t_stock		stock;
	int			i;

	va_start(stru.ap, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			ft_find_indicator(&format[i], &stru, &stock);
			ft_check_width(&format[i], &stru);
			ft_check_precision(&format[i], &stru);
			ft_check_flags(&format[i], &stru, &stock);
			while (format[i] != stru.indic)
				i++;
		}
		else if (format[i] != '%')
			write(1, &format[i], 1);
		i++;
	}
	va_end(stru.ap);
	return (0);
}

#include <limits.h>

int main(int argc, const char *argv[])
{
//	ft_printf("test o : %o\n", 405345);
//	printf("test o : %o\n", 405345);
	ft_printf("test o : %o\n", 9223372036854775807);
	printf("printf : %o\n", 9223372036854775807);
//	printf("atoi : %ld\n", LONG_MAX);
	return 0;
}

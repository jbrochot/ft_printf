/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:33:05 by jebrocho          #+#    #+#             */
/*   Updated: 2019/01/17 17:31:05 by jebrocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char		*ft_convert_o(long long octal_int)
{
	int			i;
	char		*str;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * 22)))
		return (NULL);
	while (octal_int != 0)
	{
		str[i] = octal_int % 8 + 48;
//		printf("\nitoa_mod : %lld\n", octal_int % 8);
//		printf("str : %s\n", str);
		octal_int /= 8;
		i++;
	}
	str[i] = '\0';
	str = ft_strrev(str);
	return (str);
}

void		ft_indic_o(t_struct *stru, t_stock *stock)
{
	if (stru->flag[3] == 1)
		stru->flag[3] = 0;
	if (stock->stock_i > 2147483647 && stru->flag[7] == 0 && stru->flag[8] == 0)
		stock->stock_i = stock->stock_i - (9223372036854775807 - 4294967295);
	if ((stock->stock_s = ft_convert_o(stock->stock_i)) == NULL)
		return ;
	ft_putstr(stock->stock_s);
	stock->stock_i = ft_atoi(stock->stock_s);
	free(stock->stock_s);
//	ft_indic_di(stru, stock);
}

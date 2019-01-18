/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 13:36:39 by ezonda            #+#    #+#             */
/*   Updated: 2019/01/17 17:23:58 by jebrocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_dispatch(t_struct *stru, t_stock *stock)
{
	if (stru->indic == 'c')
		ft_indic_c(stru, stock);
	if (stru->indic == 's')
		ft_indic_s(stru, stock);
	if (stru->indic == 'p')
		ft_indic_p(stru, stock);
	if (stru->indic == 'd' || stru->indic == 'i')
		ft_indic_di(stru, stock);
	if (stru->indic == 'o')
		ft_indic_o(stru, stock);
	if (stru->indic == 'u')
		;
	if (stru->indic == 'x' || stru->indic == 'X')
		ft_indic_x(stru, stock);
	if (stru->indic == 'f')
		ft_indic_f(stru, stock);
//	ft_initialize_flags(stru);
}

void	ft_stock(t_stock *stock, t_struct *stru)
{
	if ((stru->indic == 'd' || stru->indic == 'i' || stru->indic == 'o'
			|| stru->indic == 'u' || stru->indic == 'x' || stru->indic == 'X')
			&& stru->flag[7] == 0 && stru->flag[8] == 0)
		stock->stock_i = va_arg(stru->ap, long);
	else if ((stru->indic == 'd' || stru->indic == 'i' || stru->indic == 'o'
				|| stru->indic == 'u' || stru->indic == 'x'
				|| stru->indic == 'X') && stru->flag[8] == 1)
		stock->stock_il = va_arg(stru->ap, long);
	else if ((stru->indic == 'd' || stru->indic == 'i' || stru->indic == 'o'
				|| stru->indic == 'u' || stru->indic == 'x'
				|| stru->indic == 'X') && stru->flag[7] == 1)
		stock->stock_ill = va_arg(stru->ap, long long);
	if (stru->indic == 'c')
		stock->stock_c = (char)va_arg(stru->ap, int);
	if (stru->indic == 's')
		stock->stock_s = va_arg(stru->ap, char*);
	if (stru->indic == 'f')
		stock->stock_f = va_arg(stru->ap, double);
	if (stru->indic == 'p')
		stock->stock_p = va_arg(stru->ap, void*);
}

void	ft_initialize_flags(t_struct *stru)
{
	int i;

	i = 0;
	while (i < 10)
	{
		stru->flag[i] = 0;
		i++;
	}
}

int		ft_nbrsize(int nb)
{
	int		size;

	size = 0;
	if (nb < 0)
	{
		nb *= -1;
		size++;
	}
	if (nb == 0)
		size++;
	while (nb > 0)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

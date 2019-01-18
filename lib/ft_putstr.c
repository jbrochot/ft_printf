/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:05:10 by ezonda            #+#    #+#             */
/*   Updated: 2019/01/16 12:58:28 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"

void	ft_putstr(const char *s)
{
	int i;

	i = 0;
	if (!(s))
		return ;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

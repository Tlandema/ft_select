/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:45:32 by tlandema          #+#    #+#             */
/*   Updated: 2019/04/26 15:24:38 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

int		ft_looper(t_trm *trm)
{
	long	test;
	
	while (1)
	{
		ft_print_args(trm);
		test = 0;
		read(0, &test, 8);
		ft_putnbr(test);
		if (ft_key_press(test, trm) == 1)
			return (0);
		else
			return (1);
	}
}

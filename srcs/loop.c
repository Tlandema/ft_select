/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:45:32 by tlandema          #+#    #+#             */
/*   Updated: 2019/04/27 16:37:10 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

int		ft_looper(void)
{
	long	test;
	int		ret;
	
	while (1)
	{
		ft_print_args();
		test = 0;
		read(0, &test, 8);
		ft_putnbr(test);
		ret = ft_key_press(test);
		if (ret == 1)
			return (1);
		else if (ret == 2)
			return (0);
	}
}

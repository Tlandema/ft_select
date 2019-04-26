/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:21:49 by tlandema          #+#    #+#             */
/*   Updated: 2019/04/26 15:23:02 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	ft_print_args(t_trm *trm)
{
	t_arg	*args;
	t_arg	*first;
	int		i;

	i = 0;
	first = trm->args;
	args = trm->args;
	ft_putstr_fd(tgetstr("cl", NULL), 0);
	while (args && (args != first || i == 0))
	{
		if (args == trm->the_arg)
			ft_putstr(tgetstr("mr", NULL));
		if (args->selected == 1)
			ft_putstr(tgetstr("us", NULL));
		ft_putstr_fd(args->name, 0);
		ft_putstr(tgetstr("me", NULL));
		ft_putchar_fd(' ', 0);
		if (args->right)
			args = args->right;		
		else
			return ;
		i = 1;
	}
}

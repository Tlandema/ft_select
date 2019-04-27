/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:21:49 by tlandema          #+#    #+#             */
/*   Updated: 2019/04/27 14:53:42 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void		ft_print_args(void)
{
	t_arg	*args;
	t_arg	*first;
	int		i;
	int		j;

	ft_arg_size_max();
	i = 0;
	j = 0;
	first = g_trm->args;
	args = first;
	ft_putstr_fd(tgetstr("cl", NULL), 0);
	while (args && (args != first || i == 0))
	{
		if (args == g_trm->the_arg)
			ft_putstr(tgetstr("mr", NULL));
		if (args->selected == 1)
			ft_putstr(tgetstr("us", NULL));
		j++;
		ft_print_with_pad(args->name, g_trm->size_max, j == g_trm->nb_p_l);
		if (j == g_trm->nb_p_l)
			j = 0;
		args = args->right;		
		i = 1;
	}
}

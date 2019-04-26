/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:21:49 by tlandema          #+#    #+#             */
/*   Updated: 2019/04/26 20:58:43 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static int	ft_shame(void)
{
	ft_putchar('\n');
	return (0);
}

void		ft_print_args(t_trm *trm)
{
	t_arg	*args;
	t_arg	*first;
	int		i;
	int		j;

	ft_arg_size_max(trm);
	i = 0;
	j = 0;
	first = trm->args;
	args = first;
	ft_putstr_fd(tgetstr("cl", NULL), 0);
	while (args && (args != first || i == 0))
	{
		if (j == trm->nb_p_l)
			j = ft_shame();
		if (args == trm->the_arg)
			ft_putstr(tgetstr("mr", NULL));
		if (args->selected == 1)
			ft_putstr(tgetstr("us", NULL));
		ft_print_with_pad(args->name, trm->size_max);
		args = args->right;		
		i = 1;
		j++;
	}
}

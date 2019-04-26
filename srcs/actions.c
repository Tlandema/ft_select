/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 18:43:24 by tlandema          #+#    #+#             */
/*   Updated: 2019/04/26 21:45:54 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	ft_move_up(t_trm *trm)
{
	int		i;
	t_arg	*actual;

	i = 0;
	actual = trm->the_arg;
	while (i < trm->nb_p_l)
	{
		if (trm->the_arg == trm->args)
		{
			trm->the_arg = actual;
			return ;
		}
		trm->the_arg = trm->the_arg->left;
		i++;
	}
}

void	ft_move_down(t_trm *trm)
{
	int		i;
	t_arg	*actual;
	int		j;


	j = 0;
	i = 0;
	actual = trm->the_arg;
	while (i < trm->nb_p_l)
	{
		if (trm->the_arg == trm->args && j != 0)
		{
			trm->the_arg = actual;
			return ;
		}
		trm->the_arg = trm->the_arg->right;
		i++;
		j = 1;
	}
}

int		ft_key_press(long test, t_trm *trm)
{
	if (test == 27)
		return (1);
	else if (test == 32 && trm->the_arg->selected == 0)
		trm->the_arg->selected = 1;
	else if (test == 32 && trm->the_arg->selected == 1)
		trm->the_arg->selected = 0;
	else if (test == 4414235)
		trm->the_arg = trm->the_arg->right;
	else if (test == 4479771)
		trm->the_arg = trm->the_arg->left; 
	else if (test == 4283163)
		ft_move_up(trm);
	else if (test == 4348699)
		ft_move_down(trm);
	else if (test == 10)
		return (1);
	return (0);
}

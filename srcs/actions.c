/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 18:43:24 by tlandema          #+#    #+#             */
/*   Updated: 2019/04/27 14:57:18 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static void	ft_move_up(void)
{
	int		i;
	t_arg	*actual;

	i = 0;
	actual = g_trm->the_arg;
	while (i < g_trm->nb_p_l)
	{
		if (g_trm->the_arg == g_trm->args)
		{
			g_trm->the_arg = actual;
			return ;
		}
		g_trm->the_arg = g_trm->the_arg->left;
		i++;
	}
}

static void	ft_move_down(void)
{
	int		i;
	t_arg	*actual;
	int		j;


	j = 0;
	i = 0;
	actual = g_trm->the_arg;
	while (i < g_trm->nb_p_l)
	{
		if (g_trm->the_arg == g_trm->args && j != 0)
		{
			g_trm->the_arg = actual;
			return ;
		}
		g_trm->the_arg = g_trm->the_arg->right;
		i++;
		j = 1;
	}
}

int		ft_key_press(long test)
{
	if (test == 27)
		return (1);
	else if (test == 32 && g_trm->the_arg->selected == 0)
		g_trm->the_arg->selected = 1;
	else if (test == 32 && g_trm->the_arg->selected == 1)
		g_trm->the_arg->selected = 0;
	else if (test == 4414235)
		g_trm->the_arg = g_trm->the_arg->right;
	else if (test == 4479771)
		g_trm->the_arg = g_trm->the_arg->left; 
	else if (test == 4283163)
		ft_move_up();
	else if (test == 4348699)
		ft_move_down();
	else if (test == 10)
		return (1);
	return (0);
}

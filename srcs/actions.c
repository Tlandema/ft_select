/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 18:43:24 by tlandema          #+#    #+#             */
/*   Updated: 2019/04/29 08:48:35 by tlandema         ###   ########.fr       */
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
		g_trm->the_arg = g_trm->the_arg->right;
		i++;
		if (g_trm->the_arg == g_trm->args && j != 0)
		{
			g_trm->the_arg = actual;
			return ;
		}
		j = 1;
	}
}

static void	ft_space_dealer(void)
{
	if (g_trm->the_arg->selected == 1)
		g_trm->the_arg->selected = 0;
	else
		g_trm->the_arg->selected = 1;
	g_trm->the_arg = g_trm->the_arg->right;
}

static int	ft_delete_arg(void)
{
	t_arg	*tmp;

	tmp = g_trm->the_arg;
	if (g_trm->the_arg == g_trm->args)
		g_trm->args = g_trm->args->right;
	if (g_trm->the_arg->left == g_trm->the_arg
			|| g_trm->the_arg->right == g_trm->the_arg)
		return (2);
	g_trm->the_arg->left->right = g_trm->the_arg->right;
	g_trm->the_arg->right->left = g_trm->the_arg->left;
	g_trm->the_arg = g_trm->the_arg->right;
	free(tmp->name);
	free(tmp);
	return (0);
}

int			ft_key_press(long test)
{
	if (test == 27)
		return (2);
	else if (test == 32)
		ft_space_dealer();
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
	else if (test == 127 || test == 2117294875)
		return (ft_delete_arg());
	return (0);
}

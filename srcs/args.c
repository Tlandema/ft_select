/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 11:38:36 by tlandema          #+#    #+#             */
/*   Updated: 2019/04/29 00:00:37 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static t_arg	*ft_create_arg(char *name, int select)
{
	t_arg	*arg;

	arg = (t_arg *)ft_memalloc(sizeof(t_arg));
	arg->name = ft_strdup(name);
	arg->selected = select;
	return (arg);
}

static void		ft_argumenting(t_arg **arg, char *name, int count)
{
	static int i = 0;

	if (*arg == NULL)
	{
		*arg = ft_create_arg(name, 0);
		i++;
		if (i == count)
		{
			(*arg)->right = g_trm->args;
			g_trm->args->left = *arg;
			g_trm->the_arg = g_trm->args;
		}
		return ;
	}
	else
	{
		ft_argumenting(&(*arg)->right, name, count);
		(*arg)->right->left = *arg;
	}
}

void			ft_arg_dealer(char **argv)
{
	int i;
	int count;

	i = 0;
	count = ft_count_tab(argv);
	while (argv[i])
	{
		if (!argv[i][0])
		{
			ft_putstr("You can't select nothing...\n");
			exit(1);
		}
		else
			ft_argumenting(&g_trm->args, argv[i], count);
		i++;
	}
	g_trm->the_arg = g_trm->args;
}

static int		ft_count_select_arg(void)
{
	t_arg	*args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	args = g_trm->args;
	while (args && (args != g_trm->args || i == 0))
	{
		if (args->selected == 1)
			j++;
		args = args->right;
		i = 1;
	}
	return (j);
}

void			ft_return_args(void)
{
	t_arg	*args;
	int		i;
	int		count_selected;
	int		j;

	j = 0;
	i = 0;
	args = g_trm->args;
	count_selected = ft_count_select_arg();
	while (args && (args != g_trm->args || i == 0))
	{
		if (args->selected == 1)
		{
			ft_putstr_fd(args->name, STDOUT_FILENO);
			j++;
			if (j != count_selected)
				ft_putchar_fd(' ', STDOUT_FILENO);
		}
		args = args->right;
		i++;
	}
}

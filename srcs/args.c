/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 11:38:36 by tlandema          #+#    #+#             */
/*   Updated: 2019/04/27 16:54:56 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

t_arg	*ft_create_arg(char *name, int select)
{
	t_arg	*arg;

	arg = (t_arg *)ft_memalloc(sizeof(t_arg));
	arg->name = ft_strdup(name);
	arg->selected = select;
	return (arg);
}

static void	ft_argumenting(t_arg **arg, char *name, int count)
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

void	ft_arg_dealer(char **argv)
{
	int i;
	int count;

	i = 0;
	g_trm->the_arg = (t_arg *)ft_memalloc(sizeof(t_arg));
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

void	ft_return_args(void)
{
	t_arg	*first;
	t_arg	*args;
	int		i;

	i = 0;
	first = g_trm->args;
	args = g_trm->args;
	while (args && (args != first || i == 0))
	{
		if (args->selected == 1)
		{
			ft_putstr_fd(args->name, STDOUT_FILENO);
			ft_putchar_fd(' ', STDOUT_FILENO);
		}
		args = args->right;
		i = 1;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 11:38:36 by tlandema          #+#    #+#             */
/*   Updated: 2019/04/26 17:25:09 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static t_arg	*ft_create_arg(char *name)
{
	t_arg	*arg;

	arg = (t_arg *)ft_memalloc(sizeof(t_arg));
	arg->name = ft_strdup(name);
	arg->selected = 0;
	ft_putstr(arg->name);
	ft_putchar(' ');
	return (arg);
}

static void	ft_argumenting(t_trm *trm, t_arg **arg, char *name, int count)
{
	static int i = 0;

	if (*arg == NULL)
	{
		*arg = ft_create_arg(name);
		i++;
		if (i == count)
		{
			(*arg)->right = trm->args;			
			trm->args->left = *arg;
			trm->the_arg = trm->args;
		}
		return ;
	}
	else
	{
		ft_argumenting(trm, &(*arg)->right, name, count);
		(*arg)->right->left = *arg;
	}
}

void	ft_arg_dealer(t_trm *trm, char **argv)
{
	int i;
	int count;

	i = 0;
	trm->the_arg = (t_arg *)ft_memalloc(sizeof(t_arg));
	count = ft_count_tab(argv);
	while (argv[i])
	{
		if (!argv[i][0])
		{
			ft_putstr("You can't select nothing...\n");
			exit(1);
		}
		else
			ft_argumenting(trm, &trm->args, argv[i], count);
		i++;
	}
	trm->the_arg = trm->args;
}

void	ft_return_args(t_trm *trm)
{
	t_arg	*first;
	t_arg	*args;
	int		i;

	i = 0;
	first = trm->args;
	args = trm->args;
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

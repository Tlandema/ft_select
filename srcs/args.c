/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <tlandema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 11:38:36 by tlandema          #+#    #+#             */
/*   Updated: 2020/02/16 05:06:48 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static t_arg	*ft_create_arg(char *name, int select)
{
	t_arg	*arg;

	if ((arg = (t_arg *)ft_memalloc(sizeof(t_arg))) == NULL)
		return (NULL);
	if ((arg->name = ft_strdup(name)) == NULL)
	{
		ft_memdel((void **)&arg);
		return (NULL);
	}
	arg->selected = select;
	return (arg);
}

static int8_t	ft_argumenting(t_arg **arg, char *name, int count)
{
	static int i = 0;

	if (*arg == NULL)
	{
		if ((*arg = ft_create_arg(name, 0)) == NULL)
			return (FAILURE);
		i++;
		if (i == count)
		{
			(*arg)->right = g_trm->args;
			g_trm->args->left = *arg;
			g_trm->the_arg = g_trm->args;
		}
	}
	else
	{
		if (ft_argumenting(&(*arg)->right, name, count) == FAILURE)
			return (FAILURE);
		(*arg)->right->left = *arg;
	}
	return (SUCCESS);
}

int8_t			ft_arg_dealer(char **argv)
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
			exit(ft_big_free(1));
		}
		else if (ft_argumenting(&g_trm->args, argv[i], count) == FAILURE)
			return (FAILURE);
		i++;
	}
	g_trm->the_arg = g_trm->args;
	return (SUCCESS);
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

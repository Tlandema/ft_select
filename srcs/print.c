/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:21:49 by tlandema          #+#    #+#             */
/*   Updated: 2019/04/30 04:32:26 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"
#include <sys/ioctl.h>

int			col_number(void)
{
	struct winsize	w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	return (w.ws_col);
}

static void	ft_arg_size_max(void)
{
	t_arg	*args;
	int		i;
	int		j;

	args = g_trm->args;
	i = 0;
	j = 0;
	while (args && (args != g_trm->args || i == 0))
	{
		if ((int)ft_strlen(args->name) > g_trm->size_max)
			g_trm->size_max = ft_strlen(args->name);
		args = args->right;
		i = 1;
		j++;
	}
	if ((g_trm->nb_p_l = (col_number() / (g_trm->size_max + 1))) == 0)
		g_trm->nb_p_l = 1;
	if (g_trm->nb_p_l > j)
		g_trm->nb_p_l = j;
}

static void	ft_print_with_pad(char *name, int size, int bol)
{
	int	i;
	int	j;

	j = -1;
	i = (int)ft_strlen(name);
	ft_color(name);
	ft_putstr_fd(tgetstr("me", NULL), STDERR_FILENO);
	if (bol == 1)
		ft_putchar_fd('\n', STDERR_FILENO);
	else
	{
		while (i <= size)
		{
			ft_putchar_fd(' ', STDERR_FILENO);
			i++;
		}
	}
}

void		ft_print_args(void)
{
	t_arg	*args;
	int		i;
	int		j;

	ft_arg_size_max();
	i = 0;
	j = 0;
	args = g_trm->args;
	ft_putstr_fd(tgetstr("cl", NULL), STDERR_FILENO);
	ft_header();
	while (args && (args != g_trm->args || i == 0))
	{
		if (args->selected == 1)
			ft_putstr_fd(tgetstr("mr", NULL), STDERR_FILENO);
		if (args == g_trm->the_arg)
			ft_putstr_fd(tgetstr("us", NULL), STDERR_FILENO);
		j++;
		ft_print_with_pad(args->name, g_trm->size_max, j == g_trm->nb_p_l);
		if (j == g_trm->nb_p_l)
			j = 0;
		args = args->right;
		i = 1;
	}
}

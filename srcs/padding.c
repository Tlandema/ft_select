/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 18:15:38 by tlandema          #+#    #+#             */
/*   Updated: 2019/04/27 16:24:09 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"
#include <sys/ioctl.h>

void		ft_print_with_pad(char *name, int size, int bol)
{
	int	i;

	i = (int)ft_strlen(name);
	ft_putstr_fd(name, STDERR_FILENO);
	ft_putstr(tgetstr("me", NULL));
	if (bol == 1)
		ft_putchar('\n');
	else
	{
		while (i <= size)
		{
			ft_putchar(' ');
			i++;
		}
	}
}

void	ft_arg_size_max(void)
{
	t_arg	*args;
	t_arg	*first;
	int		i;

	args = g_trm->args;
	first = args;
	i = 0;
	while (args && (args != first || i == 0))
	{
		if ((int)ft_strlen(args->name) > g_trm->size_max)
			g_trm->size_max = ft_strlen(args->name);
		args = args->right;
		i = 1;
	}
	if ((g_trm->nb_p_l = (size_tab() / (g_trm->size_max + 1))) == 0)
		g_trm->nb_p_l = 1;
}

int		size_tab(void)
{
	struct winsize	w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, & w);
	return (w.ws_col);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 09:21:25 by tlandema          #+#    #+#             */
/*   Updated: 2019/04/30 06:56:09 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static void	ft_free(t_arg *to_f)
{
	if (to_f->right && to_f->right != g_trm->args)
		ft_free(to_f->right);
	free(to_f->name);
	free(to_f);
}

void		ft_big_free(void)
{
	ft_free(g_trm->args);
	free(g_trm->my_t);
	free(g_trm->old_t);
	free(g_trm);
}

int			main(int argc, char **argv)
{
	int		ret;

	ret = 0;
	if (argc < 2)
		ft_print_usage();
	g_trm = (t_trm *)ft_memalloc(sizeof(t_trm));
	if (ft_init_term() == -1)
		return (-1);
	ft_init_signals();
	ft_arg_dealer(&argv[1]);
	ret = ft_looper();
	if (ft_reset_term() == -1)
		return (-1);
	if (ret == 1)
		ft_return_args();
	ft_big_free();
	return (0);
}

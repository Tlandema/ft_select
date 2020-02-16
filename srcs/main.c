/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <tlandema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 09:21:25 by tlandema          #+#    #+#             */
/*   Updated: 2020/02/16 05:03:40 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static void	ft_free(t_arg *to_f)
{
	if (to_f->right && to_f->right != g_trm->args)
		ft_free(to_f->right);
	ft_strdel(&to_f->name);
	ft_memdel((void **)&to_f);
}

int8_t		ft_big_free(int8_t ret)
{
	if (g_trm->args)
		ft_free(g_trm->args);
	ft_memdel((void **)&g_trm->my_t);
	ft_memdel((void **)&g_trm->old_t);
	ft_memdel((void **)&g_trm);
	return (ret);
}

int			main(int argc, char **argv)
{
	int		ret;

	ret = 0;
	if (argc < 2)
		ft_print_usage();
	if ((g_trm = (t_trm *)ft_memalloc(sizeof(t_trm))) == NULL)
		return (1);
	if (ft_init_term() == FAILURE)
		return (ft_big_free(1));
	ft_init_signals();
	if (ft_arg_dealer(&argv[1]) == FAILURE)
		return (ft_big_free(1));
	ret = ft_looper();
	if (ft_reset_term() == FAILURE)
		return (ft_big_free(1));
	if (ret == 1)
		ft_return_args();
	return (ft_big_free(0));
}

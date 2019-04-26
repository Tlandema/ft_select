/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 09:21:25 by tlandema          #+#    #+#             */
/*   Updated: 2019/04/26 22:01:54 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

int		main(int argc, char **argv)
{
	t_trm	*trm;
	int		ret;

	if (argc < 2)
		ft_print_usage();
	trm = (t_trm *)ft_memalloc(sizeof(t_trm));
	if (ft_init_term(trm) == -1)
		return (-1);
	//init_signal_handler();
	ft_arg_dealer(trm, &argv[1]);
	ret = ft_looper(trm);
	if (ft_reset_term(trm) == -1)
		return (-1);
	if (ret == 1)
		ft_return_args(trm);
	return (0);
}

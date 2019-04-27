/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 09:21:25 by tlandema          #+#    #+#             */
/*   Updated: 2019/04/27 14:58:45 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

int		main(int argc, char **argv)
{
	int		ret;

	if (argc < 2)
		ft_print_usage();
	g_trm = (t_trm *)ft_memalloc(sizeof(t_trm));
	if (ft_init_term() == -1)
		return (-1);
	//init_signal_handler();
	ft_arg_dealer(&argv[1]);
	ret = ft_looper();
	if (ft_reset_term() == -1)
		return (-1);
	if (ret == 1)
		ft_return_args();
	return (0);
}

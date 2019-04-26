/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 09:21:25 by tlandema          #+#    #+#             */
/*   Updated: 2019/04/26 15:26:45 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

int		main(int argc, char **argv)
{
	t_trm	*trm;

	if (argc < 2)
		ft_print_usage();
	trm = (t_trm *)ft_memalloc(sizeof(t_trm));
	if (ft_init_term(trm) == -1)
		return (-1);
	ft_arg_dealer(trm, &argv[1]);
	ft_looper(trm);
	/*fonction de gestion de signal*/

	/*fonction de boucle permettant les actions (move, leave, choose, ...)*/

	/*fonction de renvoie des arguments séléctionnés*/
	if (ft_reset_term(trm) == -1)
		return (-1);
	return (0);
}

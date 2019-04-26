/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 18:43:24 by tlandema          #+#    #+#             */
/*   Updated: 2019/04/26 15:18:36 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

int	ft_key_press(long test, t_trm *trm)
{
	if (test == 27)
		return (1);
	else if (test == 32 && trm->the_arg->selected == 0)
		trm->the_arg->selected = 1;
	else if (test == 32 && trm->the_arg->selected == 1)
		trm->the_arg->selected = 0;
	else if (test == 4414235)
		trm->the_arg = trm->the_arg->right;
	else if (test == 4479771)
		trm->the_arg = trm->the_arg->left; 
	return (0);
}

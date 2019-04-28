/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 11:19:19 by tlandema          #+#    #+#             */
/*   Updated: 2019/04/28 17:40:36 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	ft_print_usage(void)
{
	ft_putstr_fd("Usage: ./ft_select arg1 [arg2] ...\n", STDERR_FILENO);
	exit(0);
}

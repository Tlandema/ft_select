/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 00:08:55 by tlandema          #+#    #+#             */
/*   Updated: 2019/04/30 03:33:21 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static void	ft_header_helper(int col)
{
	int i;

	i = -1;
	while (++i < col)
		ft_putchar_fd('_', STDERR_FILENO);
	ft_putstr_fd("\n|", STDERR_FILENO);
	i = -1;
	while (++i < col - 2)
		ft_putchar_fd(' ', STDERR_FILENO);
	ft_putstr_fd("|\n|", STDERR_FILENO);
	i = -1;
	while (++i < ((col - 12) / 2) + ((col - 12) % 2))
		ft_putchar_fd(' ', STDERR_FILENO);
	ft_putstr_fd("\033[31mFT_SELECT\033[39m", STDERR_FILENO);
	i = -1;
	while (++i < ((col - 10) / 2))
		ft_putchar_fd(' ', STDERR_FILENO);
	ft_putstr_fd("|\n|", STDERR_FILENO);
	i = -1;
}

void		ft_header(void)
{
	int col;
	int i;

	i = -1;
	col = col_number();
	if (col_number() >= 11)
	{
		ft_header_helper(col);
		while (++i < col - 2)
			ft_putchar_fd(' ', STDERR_FILENO);
		ft_putstr_fd("|\n", STDERR_FILENO);
		i = -1;
		while (++i < col)
			ft_putchar_fd('_', STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
}

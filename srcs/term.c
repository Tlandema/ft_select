/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <tlandema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 10:32:08 by tlandema          #+#    #+#             */
/*   Updated: 2020/02/16 05:07:11 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static int8_t	free_ret(void *to_f1, void *to_f2)
{
	ft_memdel((void **)&to_f1);
	ft_memdel((void **)&to_f2);
	return (FAILURE);
}

int8_t			ft_init_term(void)
{
	char	*term_name;

	if (!(g_trm->my_t = (struct termios *)ft_memalloc(sizeof(struct termios))))
		return (FAILURE);
	if (!(g_trm->old_t = (struct termios *)ft_memalloc(sizeof(struct termios))))
		return (free_ret(g_trm->my_t, NULL));
	if ((term_name = getenv("TERM")) == NULL)
		return (free_ret(g_trm->my_t, g_trm->old_t));
	if (tgetent(NULL, term_name) < 1)
		return (free_ret(g_trm->my_t, g_trm->old_t));
	tcgetattr(STDERR_FILENO, g_trm->my_t);
	tcgetattr(STDERR_FILENO, g_trm->old_t);
	g_trm->my_t->c_lflag &= ~(ICANON);
	g_trm->my_t->c_lflag &= ~(ECHO);
	g_trm->my_t->c_cc[VMIN] = 1;
	g_trm->my_t->c_cc[VTIME] = 0;
	if (tcsetattr(STDERR_FILENO, TCSADRAIN, g_trm->my_t) == FAILURE)
		return (free_ret(g_trm->my_t, g_trm->old_t));
	tputs(tgetstr("ti", NULL), 1, ft_printest);
	tputs(tgetstr("vi", NULL), 1, ft_printest);
	g_trm->size_max = 0;
	g_trm->nb_p_l = 0;
	return (SUCCESS);
}

int8_t			ft_reset_term(void)
{
	tputs(tgetstr("ve", NULL), 1, ft_printest);
	tputs(tgetstr("te", NULL), 1, ft_printest);
	if (tcsetattr(0, TCSANOW, g_trm->old_t) == FAILURE)
		return (FAILURE);
	return (0);
}

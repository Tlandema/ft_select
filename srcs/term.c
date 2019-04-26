/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 10:32:08 by tlandema          #+#    #+#             */
/*   Updated: 2019/04/26 20:32:49 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

int     ft_init_term(t_trm *trm)
{
	char    *term_name;

	trm->my_t = (struct termios *)ft_memalloc(sizeof(struct termios));
	trm->old_t = (struct termios *)ft_memalloc(sizeof(struct termios));
	if ((term_name = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, term_name) < 1)
		return (-1);
	tcgetattr(STDIN_FILENO, trm->my_t);
	tcgetattr(STDIN_FILENO, trm->old_t);
	trm->my_t->c_lflag &= ~(ICANON);
	trm->my_t->c_lflag &= ~(ECHO);
	trm->my_t->c_cc[VMIN] = 1;
	trm->my_t->c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, trm->my_t) == -1)
		return (-1);
	tputs(tgetstr("ti", NULL), 1 , ft_printest);
	tputs(tgetstr("vi", NULL), 1 , ft_printest);
	trm->size_max = 0;
	trm->nb_p_l = 0;
	return (0);
}

int     ft_reset_term(t_trm *trm)
{

	tputs(tgetstr("ve", NULL), 1 , ft_printest);
	tputs(tgetstr("te", NULL), 1 , ft_printest);
	if (tcsetattr(0, TCSANOW, trm->old_t) == -1)
		return (-1);
	return (0);
}

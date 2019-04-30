/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 10:32:08 by tlandema          #+#    #+#             */
/*   Updated: 2019/04/30 04:53:14 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

int	ft_init_term(void)
{
	char	*term_name;

	g_trm->my_t = (struct termios *)ft_memalloc(sizeof(struct termios));
	g_trm->old_t = (struct termios *)ft_memalloc(sizeof(struct termios));
	if ((term_name = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, term_name) < 1)
		return (-1);
	tcgetattr(STDERR_FILENO, g_trm->my_t);
	tcgetattr(STDERR_FILENO, g_trm->old_t);
	g_trm->my_t->c_lflag &= ~(ICANON);
	g_trm->my_t->c_lflag &= ~(ECHO);
	g_trm->my_t->c_cc[VMIN] = 1;
	g_trm->my_t->c_cc[VTIME] = 0;
	if (tcsetattr(STDERR_FILENO, TCSADRAIN, g_trm->my_t) == -1)
		return (-1);
	tputs(tgetstr("ti", NULL), 1, ft_printest);
	tputs(tgetstr("vi", NULL), 1, ft_printest);
	g_trm->size_max = 0;
	g_trm->nb_p_l = 0;
	return (0);
}

int	ft_reset_term(void)
{
	tputs(tgetstr("ve", NULL), 1, ft_printest);
	tputs(tgetstr("te", NULL), 1, ft_printest);
	if (tcsetattr(0, TCSANOW, g_trm->old_t) == -1)
		return (-1);
	return (0);
}

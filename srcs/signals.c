/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 17:32:26 by tlandema          #+#    #+#             */
/*   Updated: 2019/04/30 04:20:36 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"
#include <sys/ioctl.h>

static void	ft_suspend_signal_handler(void)
{
	ft_reset_term();
	signal(SIGTSTP, SIG_DFL);
	ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
}

static void	ft_stop_signal_handler(void)
{
	ft_reset_term();
	ft_big_free();
	exit(1);
}

static void	signal_handler(int signal)
{
	if (signal == SIGWINCH)
		ft_print_args();
	else if (signal == SIGCONT)
	{
		ft_init_term();
		ft_init_signals();
		ft_print_args();
	}
	else if (signal == SIGABRT || signal == SIGSTOP || signal == SIGINT
			|| signal == SIGKILL || signal == SIGQUIT || signal == SIGTERM)
		ft_stop_signal_handler();
	else if (signal == SIGTSTP)
		ft_suspend_signal_handler();
}

void		ft_init_signals(void)
{
	signal(SIGWINCH, signal_handler);
	signal(SIGABRT, signal_handler);
	signal(SIGINT, signal_handler);
	signal(SIGSTOP, signal_handler);
	signal(SIGTERM, signal_handler);
	signal(SIGCONT, signal_handler);
	signal(SIGTSTP, signal_handler);
	signal(SIGKILL, signal_handler);
	signal(SIGQUIT, signal_handler);
}

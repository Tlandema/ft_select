/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 06:45:11 by tlandema          #+#    #+#             */
/*   Updated: 2019/04/27 15:50:14 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

#include "../libft/includes/libft.h"
#include "../libft/includes/ft_printf.h"
#include <termios.h>
#include <termcap.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct			s_arg
{
	int					selected;
	char				*name;
	struct s_arg		*left;
	struct s_arg		*right;

}						t_arg;

typedef struct			s_trm
{
	struct termios		*my_t;
	struct termios		*old_t;
	t_arg				*args;
	t_arg				*the_arg;
	int					size_max;
	int					nb_p_l;
}						t_trm;

t_trm					*g_trm;

void					ft_init_signals(void);
//void					signal_handler(int signal);

void					ft_print_usage(void);
int						ft_printest(int);
void					ft_print_args(void);
void					ft_print_with_pad(char *name, int size, int bol);
void					ft_return_args(void);

void					ft_arg_dealer(char **argv);
void					ft_arg_size_max(void);

int						ft_looper(void);
int						ft_key_press(long test);

int						ft_init_term(void);
int						ft_reset_term(void);

int						size_tab(void);

#endif

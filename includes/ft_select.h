/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 06:45:11 by tlandema          #+#    #+#             */
/*   Updated: 2019/04/27 14:42:23 by tlandema         ###   ########.fr       */
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

void					ft_print_usage(void);
int						ft_printest(int);
void					ft_print_args(t_trm *trm);
void					ft_print_with_pad(char *name, int size, int bol);
void					ft_return_args(t_trm *trm);

void					ft_arg_dealer(t_trm *trm, char **argv);
void					ft_arg_size_max(t_trm *trm);

int						ft_looper(t_trm *trm);
int						ft_key_press(long test, t_trm *trm);

int						ft_init_term(t_trm *trm);
int						ft_reset_term(t_trm *trm);

int						size_tab(void);

#endif

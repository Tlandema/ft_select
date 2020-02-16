/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <tlandema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 06:45:11 by tlandema          #+#    #+#             */
/*   Updated: 2020/02/16 04:58:36 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# define FAILURE -1
# define SUCCESS 0

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include <termios.h>
# include <termcap.h>
# include <unistd.h>
# include <stdlib.h>

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

void					ft_print_usage(void);
int						ft_printest(int yes);
void					ft_print_args(void);
void					ft_return_args(void);

int8_t					ft_arg_dealer(char **argv);

void					ft_color(char *name);

int						ft_looper(void);
int						ft_key_press(long test);

int8_t					ft_init_term(void);
int8_t					ft_reset_term(void);

int						col_number(void);
void					ft_header(void);

int8_t					ft_big_free(int8_t ret);

#endif

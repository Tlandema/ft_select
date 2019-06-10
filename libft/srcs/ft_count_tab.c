/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 10:51:48 by tlandema          #+#    #+#             */
/*   Updated: 2019/03/18 14:03:11 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 19:28:48 by tlandema          #+#    #+#             */
/*   Updated: 2019/04/28 19:54:07 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"
#include <sys/stat.h>

void	ft_color(char *name)
{
	struct stat	file_info;

	lstat(name, &file_info);
	if (access(name, F_OK) == -1)
	{
		ft_putstr_fd(name, STDERR_FILENO);
		return ;
	}
	if (S_ISCHR(file_info.st_mode))
		ft_putstr("\033[34;43m");
	else if (S_ISDIR(file_info.st_mode))
		ft_putstr("\033[96m");
	else if (S_ISBLK(file_info.st_mode))
		ft_putstr("\033[34;46m");
	else if (S_ISLNK(file_info.st_mode))
		ft_putstr("\033[35m");
	else if ((file_info.st_mode & S_IXUSR) || (file_info.st_mode & S_IXGRP)
			|| (file_info.st_mode & S_IXOTH))
		ft_putstr("\033[31m");
	ft_putstr_fd(name, STDERR_FILENO);
	ft_putstr("\033[39;49m");
}

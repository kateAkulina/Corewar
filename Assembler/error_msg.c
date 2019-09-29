/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 15:20:54 by lcutjack          #+#    #+#             */
/*   Updated: 2019/09/28 21:37:06 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*g_msg[16] = {
	"\033[0;32m; can't allocate memory\n\033[0m",
	"\033[0;32m doesn't exist or is invalid for some reasons\n\033[0m",
	"\033[0;32m have incorrect extension  [must be \".s\"]\n\033[0m",
	"\033[0;32m; champion name is not correct\n\033[0m",
	"\033[0;32m; champion comment is not correct\n\033[0m",
	"\033[0;32m; double name\n\033[0m",
	"\033[0;32m; double comment\n\033[0m",
	"\033[0;32m; no name\n\033[0m",
	"\033[0;32m; no comment\n\033[0m",
	"\033[0;32m can't be created new file\n\033[0m",
	"\033[0;32m incorrect command:\n\033[0m",
	"\033[0;32m incorrect argument:\n\033[0m",
	"\033[0;32m incorrect number of arguments:\n\033[0m",/* 12 */
	"\033[0;32m incorrect command:\n\033[0m",
	"\033[0;32m this mark doesn't exist:\n\033[0m",
	"\033[0;32m incorrect label:\n\033[0m"
};

t_error		g_error = {NULL, 0, NULL};

void		say_error()
{
	ft_putstr_fd("\033[0;32mThe file : \033[0m", 2);
	ft_putstr_fd(g_error.filename, 2);
	ft_putstr_fd(g_msg[g_error.id], 2);
	if (g_error.id > 9)
	{
		ft_putstr_fd("             ", 2);
		ft_putendl_fd(g_error.str_er, 2);
	}
}

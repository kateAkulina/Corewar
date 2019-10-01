/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 20:26:05 by lcutjack          #+#    #+#             */
/*   Updated: 2019/10/01 14:50:55 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	write_magic(t_out *out)
{
	char	*lol;
	int		value;
	int		i;

	i = 4;
	value = COREWAR_EXEC_MAGIC;
	lol = (char*)&value;
	while (--i >= 0)
		out->head[i] = *(lol + i);
}

// (new = open(fname, O_RDWR | O_CREAT, 0600)) < 3)
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:51:12 by lcutjack          #+#    #+#             */
/*   Updated: 2019/08/31 15:40:06 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	empty(char *s, size_t n)
{
	while (n > 0)
	{
		if (*s != '\t' && *s != ' ')
			return (0);
		s++;
		n--;
	}
	return (1);
}

void skip_emptyness(char **p)
{
	while (**p == ' ' || **p == '\t')
	{
		(*p)++;
	}
}

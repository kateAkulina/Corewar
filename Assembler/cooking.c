/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cooking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 14:12:42 by lcutjack          #+#    #+#             */
/*   Updated: 2019/08/26 20:56:09 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void write_magic(t_out *out)
{
    char    *lol;
    int     value;
    int     i;

    i = 4;
    value = COREWAR_EXEC_MAGIC;
    lol = (char*)&value;
    while (--i >= 0)
        out->head[i] = *(lol + i);
}

static void read_name(int fd, t_out *out, char *line)
{
    char    *start;
	char	*end;

	if ((!(start = ft_strchr(line, '"')) || !empty(line, start - line))
		&& (out->error = 3))
		return ;
	if ((end = ft_strchr(start + 1, '"')))
		ft_strncpy(out->name, start + 1, end - start - 1);
	else
	{
		ft_strcat(out->name, start + 1);
		while (get_next_line(fd, &start) && !(end = ft_strchr(start, '"')))
		{
			ft_strcat(out->name, start);
			free(start);
		}
		ft_strncat(out->name, start, end - start - 1);
	}
	out->n_true = 1;
}

static void read_comment(int fd, t_out *out, char *line)
{
    char    *start;
	char	*end;
	
    if ((!(start = ft_strchr(line, '"')) || !empty(line, start - line))
		&& (out->error = 4))
		return ;
	if ((end = ft_strchr(start + 1, '"')))
		ft_strncpy(out->comm, start + 1, end - start - 1);
	else
	{
		ft_strcat(out->comm, start + 1);
		while (get_next_line(fd, &start) && !(end = ft_strchr(start, '"')))
		{
			ft_strcat(out->comm, start);
			free(start);
		}
		ft_strncat(out->comm, start, end - start - 1);
	}
	out->c_true = 1;
}

static void	read_n_c(int fd, t_out *out)
{
	int		i;
	char	*line;
	size_t	n_len;
	size_t	c_len;

	i = 2;
	n_len = ft_strlen(NAME_CMD_STRING);
	c_len = ft_strlen(COMMENT_CMD_STRING);
	while (i--)
	{
		while (get_next_line(fd, &line) && (!*line || *line == COMMENT_CHAR))
			ft_memdel((void**)&line);
		if (!ft_strncmp(COMMENT_CMD_STRING, line, c_len) && !out->c_true)
			read_comment(fd, out, line + c_len);
		// else if (!ft_strncmp(COMMENT_CMD_STRING, line, c_len) && out->c_true)
		// 	out->error = 6;
		else if (!ft_strncmp(NAME_CMD_STRING, line, n_len) && !out->n_true)
			read_name(fd, out, line + n_len);
		// else if (!ft_strncmp(NAME_CMD_STRING, line, n_len) && out->n_true)
		// 	out->error = 5;
		//ft_memdel((void**)&line);
		if (out->error)
			return ;
	}
}	

char    cook_raw(int fd, t_out **out)
{
	t_out	*output;
	char	err;

	if (!(output = ft_memalloc(sizeof(t_out))))
		return (0);
	ft_bzero(output, sizeof(t_out));
	write_magic(output);
	read_n_c(fd, output);
	if ((err = output->error))
	{
		free(output)
;		return (err);
	}
    read_code(fd, output);
	*out = output;
	return(0);
}

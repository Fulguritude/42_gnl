/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduquesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 18:07:23 by tduquesn          #+#    #+#             */
/*   Updated: 2017/12/22 04:53:54 by tduquesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GET_NEXT_LINE_H
# define __GET_NEXT_LINE_H

# include "libft/hdr/libft.h"

# define BUFF_SIZE 32
# define NWL_RD 1
# define EOF_RD 0
# define ERR_RD -1

/*
** Stores info of a current file description being sequentially read.
** - fd :        the open file descriptor
** - rdlen :     length of the last call to "read" (useful for EOF checks)
** - buf :       the statically allocated buffer containing the current data
**                 being read - may contain multiple newlines or none.
** - bufoffset : offset of the readhead in buf
*/

typedef struct		s_fd_info
{
	int			fd;
	int			rdlen;
	char		buf[BUFF_SIZE + 1];
	size_t		bufoffset;

}					t_fd_info;

int					get_next_line(int const fd, char **line);

#endif

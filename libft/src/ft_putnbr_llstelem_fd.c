/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_llstelem_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduquesn <tduquesn@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 01:05:52 by tduquesn          #+#    #+#             */
/*   Updated: 2017/11/28 11:44:38 by tduquesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_llstelem_fd(t_list *elem, int fd)
{
	long	nbr;

	if (!elem)
		return ;
	if (elem->content_size == 1)
		nbr = *((char*)(elem->content));
	else if (elem->content_size == 2)
		nbr = *((short*)(elem->content));
	else if (elem->content_size == 4)
		nbr = *((int*)(elem->content));
	else if (elem->content_size == 8)
		nbr = *((long*)(elem->content));
	else
		return ;
	ft_putnbr_fd(nbr, fd);
}

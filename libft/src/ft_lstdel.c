/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduquesn <tduquesn@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 21:31:50 by tduquesn          #+#    #+#             */
/*   Updated: 2017/11/30 18:32:31 by tduquesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*cur_elem;

	if (!alst || !*alst || !del)
		return ;
	while ((*alst)->next)
	{
		cur_elem = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = cur_elem;
	}
	ft_lstdelone(alst, del);
	*alst = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:18:59 by adechaji          #+#    #+#             */
/*   Updated: 2024/12/22 21:17:33 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlst;
	t_list	*nobj;
	void	*new;

	nlst = NULL;
	if (!f || !del)
		return (NULL);
	while (lst)
	{
		new = f(lst->content);
		nobj = ft_lstnew(new);
		if (!nobj)
		{
			ft_lstclear(&nlst, del);
			free(new);
			return (NULL);
		}
		ft_lstadd_back(&nlst, nobj);
		lst = lst->next;
	}
	return (nlst);
}

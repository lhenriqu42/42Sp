/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:54:03 by lhenriqu          #+#    #+#             */
/*   Updated: 2024/10/16 10:08:57 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first_element;
	t_list	*new_elem;
	t_list	*current_elem;

	if (lst == NULL)
		return (NULL);
	first_element = ft_lstnew(f(lst->content));
	if (!first_element)
		return (NULL);
	current_elem = first_element;
	lst = lst->next;
	while (lst)
	{
		new_elem = ft_lstnew(f(lst->content));
		if (!new_elem)
		{
			ft_lstclear(&first_element, del);
			return (NULL);
		}
		current_elem->next = new_elem;
		current_elem = new_elem;
		lst = lst->next;
	}
	return (first_element);
}

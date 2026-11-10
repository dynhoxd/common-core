/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabernar <jabernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 16:27:07 by jabernar          #+#    #+#             */
/*   Updated: 2026/11/10 17:25:09 by jabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head_new;
	t_list	*head_old;
	t_list	*temp;

	if (!lst || !f || !del)
		return (NULL);
	f(lst->content);
	head_old = lst;
	head_new = ft_lstnew(lst->content);
	temp = head_new;
	lst = lst->next;
	while (lst)
	{
		f(lst->content);
		temp->next = ft_lstnew(lst->content);
		lst = lst->next;
		temp = temp->next;
	}
	ft_lstclear(&head_old, del);
	return (&head_new);
}

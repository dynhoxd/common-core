/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabernar <jabernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 16:27:07 by jabernar          #+#    #+#             */
/*   Updated: 2026/11/12 15:12:06 by jabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first_node;
	t_list	*temp;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	first_node = NULL;
	while (lst)
	{
		content = f(lst->content);
		temp = ft_lstnew(content);
		if (!temp)
		{
			del(content);
			ft_lstclear(&first_node, del);
			return (NULL);
		}
		ft_lstadd_back(&first_node, temp);
		lst = lst->next;
	}
	return (first_node);
}

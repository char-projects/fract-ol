/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:46:00 by cschnath          #+#    #+#             */
/*   Updated: 2024/10/11 23:12:40 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parameters lst: The address of a pointer to a node.
del: The address of the function used to delete
the content of the node.

Return value None

External functs. free

Description Deletes and frees the given node and every
successor of that node, using the function ’del’
and	free(3).
Finally, the pointer to the list must be set to NULL
*/
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, (*del));
		*lst = tmp;
	}
	*lst = NULL;
}

/*
void	del(void *content)
{
	free(content);  // Assumes dynamic memory for content
}

int	main(void)
{
	t_list	*head;

	head = ft_lstnew(ft_strdup("First"));
	ft_lstadd_back(&head, ft_lstnew(ft_strdup("Second")));
	ft_lstadd_back(&head, ft_lstnew(ft_strdup("Third")));
	ft_lstclear(&head, del);
	printf("ft_lstclear: List cleared\n");
	return (0);
}
*/

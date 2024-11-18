/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:59:25 by cschnath          #+#    #+#             */
/*   Updated: 2024/10/11 23:15:02 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parameters lst: The address of a pointer to a node.
f: The address of the function used to iterate on
the list.
del: The address of the function used to delete
the content of a node if needed.

Return value: The new list.
NULL if the allocation fails.

External functs. malloc, free

Description: Iterates the list ’lst’ and applies the function
’f’ on the content of each node. Creates a new
list resulting of the successive applications of
the function ’f’. The ’del’ function is used to
delete the content of a node if needed.
*/
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*new;

	if (!lst)
		return (NULL);
	newlst = ft_lstnew(f(lst->content));
	if (!newlst)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, new);
		lst = lst->next;
	}
	return (newlst);
}

/*
void	*dup_content(void *content)
{
	return (ft_strdup((char *)content));  // Duplicate string content
}

void	del(void *content)
{
	free(content);  // Free allocated memory for content
}

int	main(void)
{
	t_list	*head;
	t_list	*new_list;
	t_list	*current;

	head = ft_lstnew(ft_strdup("First"));
	ft_lstadd_back(&head, ft_lstnew(ft_strdup("Second")));
	ft_lstadd_back(&head, ft_lstnew(ft_strdup("Third")));
	new_list = ft_lstmap(head, dup_content, del);
	current = new_list;
	while (current)
	{
		printf("ft_lstmap content: %s\n", (char *)current->content); 
			// Expect "First", "Second", "Third"
		current = current->next;
	}
	// Clean up new_list
	ft_lstclear(&new_list, del);
	// Clean up original list
	ft_lstclear(&head, del);
	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:45:50 by cschnath          #+#    #+#             */
/*   Updated: 2024/10/11 23:09:19 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parameters: lst (the address of a pointer to the first link of
a list), new (the address of a pointer to the node to be
added to the list)

Return value: None
External functions: None
Description: Adds the node ’new’ at the beginning of the list
*/

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*
int	main(void)
{
	t_list	*head;
	t_list	*new_node;

	head = ft_lstnew("Second");
	new_node = ft_lstnew("First");
	ft_lstadd_front(&head, new_node);
	if (head)
		printf("ft_lstadd_front: %s\n", (char *)head->content); 
			// Expect "First"
	return (0);
}
*/

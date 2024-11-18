/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:45:42 by cschnath          #+#    #+#             */
/*   Updated: 2024/10/11 23:10:55 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!*lst)
		ft_lstadd_front(lst, new);
	else
		ft_lstlast(*lst)->next = new;
}

/*
int	main(void)
{
	t_list	*head;
	t_list	*new_node;
	t_list	*last;

	head = ft_lstnew("First");
	new_node = ft_lstnew("Second");
	ft_lstadd_back(&head, new_node);
	last = ft_lstlast(head);
	if (last)
		printf("ft_lstadd_back: %s\n", (char *)last->content); 
			// Expect "Second"
	return (0);
}
*/

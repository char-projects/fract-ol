/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:54:40 by cschnath          #+#    #+#             */
/*   Updated: 2024/10/11 23:10:27 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*
int	main(void)
{
	t_list	*head;
	t_list	*last;

	head = ft_lstnew("First");
	ft_lstadd_front(&head, ft_lstnew("Second"));
	ft_lstadd_front(&head, ft_lstnew("Third"));
	last = ft_lstlast(head);
	if (last)
		printf("ft_lstlast: %s\n", (char *)last->content);  // Expect "First"
	return (0);
}
*/

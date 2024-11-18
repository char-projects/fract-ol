/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:46:36 by cschnath          #+#    #+#             */
/*   Updated: 2024/10/11 23:10:04 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 1;
	if (!lst)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
/*
int	main(void)
{
	t_list	*head;

	head = ft_lstnew("First");
	ft_lstadd_front(&head, ft_lstnew("Second"));
	ft_lstadd_front(&head, ft_lstnew("Third"));
	printf("ft_lstsize: %d\n", ft_lstsize(head));  // Expect 3
	return (0);
}
*/

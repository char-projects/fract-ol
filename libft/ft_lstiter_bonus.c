/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:58:24 by cschnath          #+#    #+#             */
/*   Updated: 2024/10/11 23:14:13 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

/*
void	print_content(void *content)
{
	printf("Content: %s\n", (char *)content);
}

int	main(void)
{
	t_list	*head;

	head = ft_lstnew("First");
	ft_lstadd_back(&head, ft_lstnew("Second"));
	ft_lstadd_back(&head, ft_lstnew("Third"));
	ft_lstiter(head, print_content);
	return (0);
}
*/

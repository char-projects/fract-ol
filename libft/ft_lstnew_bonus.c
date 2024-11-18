/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:46:26 by cschnath          #+#    #+#             */
/*   Updated: 2024/10/11 23:08:43 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parameters: content (the content to create the node with)

Return value: The new node

External functions: malloc

Description: Allocates (with malloc) and returns a new node.
The member variable ’content’ is initialized with
the value of the parameter ’content’. The variable
’next’ is initialized to NULL
*/

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

/*
int	main(void)
{
	t_list	*node;

	node = ft_lstnew("Test content");
	if (node)
		printf("ft_lstnew: %s\n", (char *)node->content);
			// Expect "Test content"
	else
		printf("ft_lstnew: NULL\n");
	return (0);
}
*/

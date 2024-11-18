/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:56:00 by cschnath          #+#    #+#             */
/*   Updated: 2024/10/11 23:12:01 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parameters lst: The node to free.
del: The address of the function used to delete the content

Return value None

External functs. free

Description Takes as a parameter a node and frees the memory of
the node’s content using the function ’del’ given
as a parameter and free the node. The memory of
’next’ must not be freed
*/

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	(*del)(lst->content);
	free(lst);
}

/*
void	del(void *content)
{
	free(content);  // Assumes dynamic memory for content
}

int	main(void)
{
	t_list	*node;

	node = ft_lstnew(ft_strdup("Content to delete"));
	if (node)
	{
		ft_lstdelone(node, del);
		printf("ft_lstdelone: Node deleted\n");
	}
	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:03:17 by cschnath          #+#    #+#             */
/*   Updated: 2024/10/12 12:01:58 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocates memory for an array of  nmemb elements
of size bytes each and returns a pointer to the allocated
memory. The memory is set to zero */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

/*
int	main(void)
{
	int	n;
	int	i;
	int	*array;
   
	n = 5;
	i = 0;
	array = (int *)ft_calloc(n, sizeof(int));
   
	if (array == NULL)
	{
		fprintf(stderr, "Memory allocation failed!\n");
		return (1);
	}
   
	printf("Array elements after calloc: ");
	while (i < n)
	{
		printf("%d ", array[i]);
		i++;
	}
	printf("\n");

	free(array);
	return (0);
}
*/

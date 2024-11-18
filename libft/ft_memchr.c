/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:46:46 by cschnath          #+#    #+#             */
/*   Updated: 2024/10/12 12:07:01 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Scans  the  initial n bytes of the memory area
pointed to by s for the first instance of c */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	character;

	str = (unsigned char *)s;
	character = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*str == character)
			return (str);
		str++;
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
	const char	*s = "Hello World!";

	printf("ft_memchr(s, 'o', 12): %s\n", (char *)ft_memchr(s, 'o', 12));
		// Expect "o World!"
	printf("ft_memchr(s, 'W', 12): %s\n", (char *)ft_memchr(s, 'W', 12));
		// Expect "World!"
	printf("ft_memchr(s, 'z', 12): %p\n", ft_memchr(s, 'z', 12));        
		// Expect NULL
	return (0);
}
*/
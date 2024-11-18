/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:48:23 by cschnath          #+#    #+#             */
/*   Updated: 2024/10/11 23:16:30 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Returns a pointer to the first occurrence of the character c in the string s

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

/*
int	main(void)
{
	const char	*s = "Hello World!";

	printf("ft_strchr(s, 'o'): %s\n", ft_strchr(s, 'o')); // Expect "o World!"
	printf("ft_strchr(s, 'W'): %s\n", ft_strchr(s, 'W')); // Expect "World!"
	printf("ft_strchr(s, 'z'): %p\n", ft_strchr(s, 'z')); // Expect NULL
	return (0);
}
*/
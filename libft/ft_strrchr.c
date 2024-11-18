/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:49:53 by cschnath          #+#    #+#             */
/*   Updated: 2024/10/11 23:16:46 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*last;

	last = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			last = &((char *)s)[i];
		i++;
	}
	if (s[i] == (char)c)
		last = &((char *)s)[i];
	if (c == '\0')
		last = &((char *)s)[i];
	return (last);
}

/*
int	main(void)
{
	const char	*s = "Hello World!";

	printf("ft_strrchr(s, 'o'): %s\n", ft_strrchr(s, 'o')); // Expect "orld!"
	printf("ft_strrchr(s, 'W'): %s\n", ft_strrchr(s, 'W')); // Expect "World!"
	printf("ft_strrchr(s, 'z'): %p\n", ft_strrchr(s, 'z')); // Expect NULL
	return (0);
}
*/
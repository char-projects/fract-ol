/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:50:11 by cschnath          #+#    #+#             */
/*   Updated: 2024/10/11 23:06:37 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parameters s: The string from which to create the substring
start: The start index of the substring in the string ’s’
len: The maximum length of the substring

Return value: The substring. NULL if the allocation fails

External functions: malloc

Description: Allocates memory with malloc and
returns a substring from the string ’s’.
The substring begins at index ’start’ and is of maximum size ’len’
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	size_t			leng;
	char			*sub;

	i = 0;
	j = 0;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		leng = ft_strlen(s) - start;
	else
		leng = len;
	sub = (char *)ft_calloc(sizeof(char), (leng + 1));
	if (!sub)
		return (NULL);
	while (s[i] && i <= ft_strlen(s))
	{
		if (i >= start && j < leng)
			sub[j++] = s[i];
		i++;
	}
	sub[j] = '\0';
	leng = 0;
	return (sub);
}
/*
int	main(void)
{
	const char	*s = "Hello World!";

	printf("ft_substr(s, 0, 5): %s\n", ft_substr(s, 0, 5));   // Expect "Hello"
	printf("ft_substr(s, 6, 5): %s\n", ft_substr(s, 6, 5));   // Expect "World"
	printf("ft_substr(s, 6, 50): %s\n", ft_substr(s, 6, 50)); // Expect "World!"
	printf("ft_substr(s, 12, 5): %s\n", ft_substr(s, 12, 5)); // Expect ""
	return 0
}
*/

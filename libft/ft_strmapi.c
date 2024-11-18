/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:49:26 by cschnath          #+#    #+#             */
/*   Updated: 2024/10/11 22:49:29 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parameters: s (the string on which to iterate),
f (the function to apply to each character)

Return value: The string created from the successive applications
of ’f’. Returns NULL if the allocation fails.

External functions: malloc

Description: Applies the function f to each character of the
string s, passing its index as the first argument and the
character itself as the second. A new string is created
(using malloc) to collect the results from the
successive applications of f
*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*new;

	i = 0;
	new = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!new)
		return (NULL);
	while (s[i])
	{
		new[i] = f(i, s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}

/*
char	to_upper(unsigned int i, char c)
{
	(void)i; // Not needed in this function
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

int	main(void)
{
	char *str = "hello, world";
	char *res = ft_strmapi(str, to_upper);
	printf("Before: %s\n", str);
	printf("After: %s\n", res);
	free(res);
}
*/

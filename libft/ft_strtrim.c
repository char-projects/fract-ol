/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:28:56 by cschnath          #+#    #+#             */
/*   Updated: 2024/10/11 22:50:01 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parameters: s1 (the string to be trimmed),
set (the reference set of characters to trim)

Return value: The trimmed string. NULL if the allocation fails

External functions: malloc

Description: Allocates (with malloc) and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string
*/

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	long	start;
	long	end;
	char	*str;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	str = 0;
	if (s1 != 0 && set != 0)
	{
		start = 0;
		end = ft_strlen(s1);
		while (s1[start] && ft_strchr(set, s1[start]))
			start++;
		while (s1[end - 1] && ft_strchr(set, s1[end - 1]) && end > start)
			end--;
		str = (char *)malloc(sizeof(char) * (end - start + 1));
		if (str)
			ft_strlcpy(str, &s1[start], end - start + 1);
	}
	return (str);
}

/*
int	main(void)
{
	char	*teststr;
	char	*testset;

	teststr = "hello world, dlrow olleh";
	testset = "hel";
	printf("%s\n", ft_strtrim(teststr, testset));
}
*/

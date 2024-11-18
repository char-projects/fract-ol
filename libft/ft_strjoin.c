/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:48:52 by cschnath          #+#    #+#             */
/*   Updated: 2024/10/11 22:48:54 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parameters: s1 (the prefix string), s2 (the suffix string)

Return value: The new string. NULL if the allocation fails

External functions: malloc

Description: Allocates (with malloc(3)) and returns a new
string, which is the result of the concatenation of ’s1’ and ’s2’
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		new[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}
/*
int	main(void)
{
	char *s1 = "hellolkawdnoidanbdoiabn";
	char *s2 = "world\0";
	printf("%s\n", ft_strjoin(s1, s2));
	free(new);
}
*/

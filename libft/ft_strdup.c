/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:48:32 by cschnath          #+#    #+#             */
/*   Updated: 2024/10/11 22:48:34 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_len(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	i;

	dup = (char *)malloc(sizeof(*s) * ft_len(s) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/*
int	main(void)
{
	const char *str = "Hello, World!";
	char *duplicated_str;

	duplicated_str = ft_strdup(str);
	if (duplicated_str == NULL)
	{
		printf("Memory allocation failed\n");
		return (1);
	}

	printf("Original: %s\n", str);
	printf("Duplicated: %s\n", duplicated_str);

	// Free the duplicated string to avoid memory leak
	free(duplicated_str);
	return (0);
}
*/
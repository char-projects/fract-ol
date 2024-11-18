/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:48:16 by cschnath          #+#    #+#             */
/*   Updated: 2024/10/11 22:48:18 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parameters: s (the string to be split),
c (the delimiter character)

Return value: The array of new strings resulting from the split.
NULL if the allocation fails

External functions: malloc, free

Description: Allocates (with malloc) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must end
with a NULL pointer
*/

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (j);
}

static int	ft_word_len(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static void	ft_free(char **str, int j)
{
	while (j > 0)
	{
		j--;
		free(str[j]);
	}
	free(str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		words;
	int		len;
	char	**array;

	i = 0;
	j = 0;
	words = ft_count_words(s, c);
	array = (char **)malloc((sizeof(char *)) * (words + 1));
	if (!array)
		return (NULL);
	while (j < words)
	{
		while (s[i] == c)
			i++;
		len = ft_word_len(s, c, i);
		array[j] = ft_substr(s, i, len);
		if (!(array[j]))
			return (ft_free(array, j), NULL);
		i += len;
		j++;
	}
	array[j] = 0;
	return (array);
}

/*
int	main(void)
{
	char *teststr = "hello world, hello Malaga";
	char testchar = ' ';
	char *test1 = "hello";
	char *test2 = "world,";
	char *test3 = "hello";
	char *test4 = "Malaga";
	printf("Count words in string: %d\n", count_words(teststr, testchar));
	printf("Count length of word 1: %d\n", word_len(test1, testchar, 0));
	printf("Count length of word 2: %d\n", word_len(test2, testchar, 0));
	printf("Count length of word 3: %d\n", word_len(test3, testchar, 0));
	printf("Count length of word 4: %d\n", word_len(test4, testchar, 0));
	printf("%s\n", *ft_split(teststr, testchar));
} */

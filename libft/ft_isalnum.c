/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:44:29 by cschnath          #+#    #+#             */
/*   Updated: 2024/10/12 12:02:48 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Checks for an alphanumeric character; it is equivalent to
(isalpha(c) || isdigit(c)) */

#include "libft.h"

int	ft_isalnum(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'));
}

/*
int	main(void)
{
	// Should return 1
        printf("Test 0: %d\n", ft_isalnum('b'));
        printf("Test 1: %d\n", ft_isalnum('W'));
        printf("Test 2: %d\n", ft_isalnum('7'));

        // Should return 0
        printf("Test 3: %d\n", ft_isalnum('*'));
        printf("Test 4: %d\n", ft_isalnum(15));

        return (0);

}
*/
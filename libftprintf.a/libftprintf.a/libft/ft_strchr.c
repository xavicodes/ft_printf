/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlourenc <xlourenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:58:09 by xlourenc          #+#    #+#             */
/*   Updated: 2024/04/29 13:36:30 by xlourenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ATEMPT 1-------------------------------------------------------------------------------
// char *ft_strchr(const char *str, int c)
// {
//     int i = 0;

//     while (str[i] != '\0') // Loop until the end of the string
//     {
//         if (str[i] == c) // Check if the character is found
//         {
//             return ((char *)str + i);
	// Return a pointer to the first occurrence of c
//         }
//         i++;
//     }

//     // If the character c is not found, return NULL
//     return (NULL);
// }

// ATEMPT 2-------------------------------------------------------------------------------
//
// char *ft_strchr(const char *str, int c)
// {
//     int i = 0;

//     while (str[i] != '\0' && str[i] != c)
	// Loop until end of string or character is found
//     {
//         i++;
//     }

//     if (str[i] == c) // Check if the character is found
//     {
//         return ((char *)str + i);
	// Return a pointer to the first occurrence of c
//     }
//     else
//     {
//         return (NULL); // Character not found, return NULL
//     }
// }

// ATEMPT 3-------------------------------------------------------------------------------
char	*ft_strchr(const char *str, int c)
{
	int	i;

	if (str == NULL) // Check if input string is NULL
	{
		return (NULL); // Return NULL if input string is NULL
	}
	i = 0;
	while (str[i] != '\0' && str[i] != (unsigned char)c)
		// Loop until end of string or character is found
	{
		i++;
	}
	if (str[i] == (unsigned char)c)
	{
		return (char *)(str + i);
	}
	return (NULL);
}

/*
int	main(void)
{
	int	c;
		const char str[20] = "Hello ma friend";

		c = 'a';
		printf("%s",(char *) strchr(str,c));
}
*/

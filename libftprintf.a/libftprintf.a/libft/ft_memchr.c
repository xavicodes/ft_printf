/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlourenc <xlourenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:43:27 by xlourenc          #+#    #+#             */
/*   Updated: 2024/04/29 13:35:09 by xlourenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
// #include <string.h>
// #include <stdio.h>

// void	*ft_memchr(const void *str, int c, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	while (((char *)str)[i] != c && i < n)
// 	{
// 		i++;
// 	}
// 	if (((char *)str)[i] == c && i < n)
// 	{
// 		return ((char *)str + i);
// 	}
// 	return (0);
// }

// int	main(void)
// {
// char	s[30] = "hello ma friend";

// printf("%s",(char *)ft_memchr(s, 2 + 256, 3));
// write(1,"\n",1);
// printf("%s",(char*)memchr(s, 2 + 256, 3));
// }
#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t				i;
	const unsigned char	*uchar_str = (const unsigned char *)str;

	i = 0;
	while (i < n)
	{
		if (uchar_str[i] == (unsigned char)c)
		{
			return (void *)(uchar_str + i); // Cast result to void*
		}
		i++;
	}
	return (0); // Return null pointer if character is not found
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xaviermonteiro <xaviermonteiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:44:28 by xlourenc          #+#    #+#             */
/*   Updated: 2024/04/22 17:48:18 by xaviermonte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t	i;

	i = 0;
	if(n == 0)
		return (0);
	while (i < n)
	{
		if (((const unsigned char *)str1)[i] != ((const unsigned char *)str2)[i])
			return (((const unsigned char *)str1)[i] - ((const unsigned char *)str2)[i]);
		i++;
	}
	return (0);
}
// #include <string.h>
// int	main(void)
// {	
// 	char s[] = {-128, 0, 127, 0};
// 	char sCpy[] = {-128, 0, 127, 0};
// 	char s2[] = {0, 0, 127, 0};
// 	char s3[] = {0, 0, 42, 0};

// 		printf("%i\n",ft_memcmp(s, s2, 1));
// 		printf("%i",memcmp(s,s2, 1));
// } 
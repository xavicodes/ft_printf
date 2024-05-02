/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlourenc <xlourenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:00:10 by xlourenc          #+#    #+#             */
/*   Updated: 2024/04/29 13:36:40 by xlourenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
	{
		return (0);
	}
	if (size != 0)
	{
		while (*src != '\0' && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		return (dst);
	}
	else
		return (0);
}
/*
int	main(void)
{
		char dst[] = "helloaaaa";
		char src[] = "world00";

		printf("%s",ft_strcpy(dst,src,sizeof(dst)));
}
*/
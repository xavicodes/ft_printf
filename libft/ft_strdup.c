/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlourenc <xlourenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:25:09 by xlourenc          #+#    #+#             */
/*   Updated: 2024/04/15 15:30:32 by xlourenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int size;

	size = ft_strlen(s) + 1;
	char *dup = malloc(size * sizeof(char));

	if (dup == 0)
	{
		return (NULL);
	}
	ft_strlcpy(dup, s, size);

	return (dup);
}
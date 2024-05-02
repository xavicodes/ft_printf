/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlourenc <xlourenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:41:47 by xlourenc          #+#    #+#             */
/*   Updated: 2024/04/29 15:14:05 by xlourenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	unsigned int i;
// 	size_t a;
// 	char *newstr;

// 	i = start;
// 	a = 0;
// 	if(len < 0)
// 		return (NULL);
// 	while (!s || !(newstr = (malloc(sizeof(char) * (len + 1)))))
// 	{
// 		return (NULL);
// 	}
// 	while (i < ft_strlen(s) && a < len)
// 	{
// 		newstr[a] = s[i];
// 		i++;
// 		a++;
// 	}
// 	newstr[a + 1] = '\0';
// 	return (newstr);
// }

//---------------ATEMPT 2 ONLY KO IN 2.test---------------------------------------
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t i;
	size_t a;
	char *newstr;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > (ft_strlen(s + start)))
		len = (ft_strlen(s+start));
	newstr = malloc(sizeof(char) * (len + 1));

	if (!newstr)
		return (NULL);
	i = start;
	a = 0;
	while (s[i] && a < len && s[a + start] != '\0')
	{
		newstr[a] = s[i];
		i++;
		a++;
	}
	newstr[a] = '\0';
	return (newstr);
}
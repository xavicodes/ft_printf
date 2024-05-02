/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlourenc <xlourenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:05:46 by xlourenc          #+#    #+#             */
/*   Updated: 2024/04/29 13:34:20 by xlourenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_digits(int n)
{
	size_t i = 1; // Start with 1 for the sign
	while (n /= 10)
	{
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char *strnum;
	long numb;
	size_t digits;
	int negative = 0;

	digits = get_digits(n);
	numb = (long)n;

	if (numb < 0)
	{
		negative = 1;
		numb = -numb;
	}

	if (!(strnum = malloc(sizeof(char) * (digits + 1 + negative))))
	{
		return (NULL);
	}

	strnum[digits + negative] = '\0';

	while (digits--)
	{
		strnum[digits + negative] = numb % 10 + '0';
		numb /= 10;
	}

	if (negative)
	{
		strnum[0] = '-';
	}

	return (strnum);
}
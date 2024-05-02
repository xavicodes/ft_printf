/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlourenc <xlourenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:17:29 by xlourenc          #+#    #+#             */
/*   Updated: 2024/04/22 13:55:46 by xlourenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_tokens(char const *str, char del)
{
	int	i;
	int	tokens;

	i = 0;
	tokens = 0;
	while (str[i])
	{
		while (str[i] == del)
			i++;
		if (str[i] != del && (i == 0 || str[i - 1] == del))
		{
			tokens++;
		}
		if (str[i])
			i++;
	}
	return (tokens);
}

int	safe_malloc(char ***v_token, int p, size_t len)
{
	int	i;

	i = 0;
	*v_token = malloc(sizeof(char *) * (p + 1));
	if (*v_token == NULL)
		return (1);
	while (i < p)
	{
		(*v_token)[i] = malloc(len);
		if ((*v_token)[i] == NULL)
		{
			while (i > 0)
			{
				free((*v_token)[i - 1]);
				i--;
			}
			free(*v_token);
			return (1);
		}
		i++;
	}
	(*v_token)[p] = NULL;
	return (0);
}

int	ft_fill(char **v_tokens, const char *s, char del)
{
	int	i;
	int	v;
	int	len;

	i = 0;
	v = 0;
	while (s[i])
	{
		len = 0;
		while (s[i] == del && s[i])
			i++;
		while (s[i] != del && s[i])
		{
			i++;
			len++;
		}
		if (len > 0)
		{
			v_tokens[v] = malloc(len + 1);
			if (v_tokens[v] == NULL)
				return (1);
			ft_strlcpy(v_tokens[v], s + i - len, len);
			v_tokens[v][len] = '\0';
			v++;
		}
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		tokens;
	char	**v_tokens;

	if (s == NULL)
		return (NULL);
	tokens = count_tokens(s, c);
	if (tokens <= 0)
		return (NULL);
	if (safe_malloc(&v_tokens, tokens, ft_strlen(s) + 1))
		return (NULL);
	if (ft_fill(v_tokens, s, c))
		return (NULL);
	return (v_tokens);
}

/* int	main(void)
{
	char str[] = " hello my friend!";
	char c = ' ';
	char **tokens = ft_split(str, c);
	if (tokens != NULL)
	{
		int i = 0;
		while (tokens[i])
		{
			printf("%s\n", tokens[i]);
			free(tokens[i]);
			i++;
		}
		free(tokens);
	}
	else
	{
		printf("Failed to split the string.\n");
	}
	return (0);
} */
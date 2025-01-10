/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:59:47 by znicola           #+#    #+#             */
/*   Updated: 2025/01/10 19:56:00 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	check_qchar(char *q_char, char current, int *in_quote)
{
	*in_quote = !(*in_quote);
	if (*in_quote)
		*q_char = current;
	else
		*q_char = '\0';
}

static size_t	count_delimiters(char const *s, char c)
{
	size_t	count;
	size_t	i;
	int		in_quote;
	char	q_char;

	i = 0;
	count = 0;
	in_quote = 0;
	if (s[0] != c && s[0] != '\0')
		count++;
	while (s[i])
	{
		if (s[i] == '\\' && s[i + 1])
			i += 2;
		if ((s[i] == '\'' || s[i] == '"') && (!in_quote || s[i] == q_char))
			check_qchar(&q_char, s[i], &in_quote);
		if (!in_quote && s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

static size_t	get_token_length(const char *s, char c, int *in_q, char *q_char)
{
	size_t	len;

	len = 0;
	while (s[len] && (*in_q || s[len] != c))
	{
		if (s[len] == '\\' && s[len + 1])
			len += 2;
		if ((s[len] == '\'' || s[len] == '"') && (!*in_q || s[len] == *q_char))
			check_qchar(q_char, s[len], in_q);
		else
			len++;
		if (!*in_q && s[len] == c)
			break ;
		len++;
	}
	return (len);
}

static void	fill_substrings(char **arr, const char *s, char c, size_t count)
{
	size_t	i;
	int		in_quote;
	size_t	len;
	char	quote_char;

	i = 0;
	in_quote = 0;
	while (i < count)
	{
		while (*s == c && !in_quote)
			s++;
		len = get_token_length(s, c, &in_quote, &quote_char);
		if (*s == '\'' || *s == '"')
		{
			s++;
			len -= 2;
		}
		arr[i] = ft_substr(s, 0, len);
		if (!arr[i])
			return ;
		s += len;
		if (in_quote && *s == quote_char)
			s++;
		i++;
	}
}

char	**ft_split_quotes(const char *s, char c)
{
	char	**arr;
	size_t	count;
	size_t	i;

	if (!s)
		return (NULL);
	count = count_delimiters(s, c);
	arr = malloc((count + 1) * sizeof(*arr));
	if (!arr)
		return (NULL);
	fill_substrings(arr, s, c, count);
	i = 0;
	while (i < count)
	{
		if (!arr[i])
		{
			while (i > 0)
				free(arr[--i]);
			free(arr);
			return (NULL);
		}
		i++;
	}
	arr[count] = NULL;
	return (arr);
}

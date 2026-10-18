/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwathits <chanatip3524@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 21:53:34 by cwathits          #+#    #+#             */
/*   Updated: 2026/10/19 01:58:26 by cwathits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			count++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (count);
}

static int	free_word_array(char **arr, size_t count)
{
	while (count > 0)
	{
		count--;
		free(arr[count]);
	}
	free(arr);
	return (0);
}

static int	extract_words(char **res, char const *s, char c)
{
	size_t	i;
	size_t	w_len;
	size_t	idx;

	i = 0;
	idx = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			w_len = 0;
			while (s[i + w_len] != '\0' && s[i + w_len] != c)
				w_len++;
			res[idx] = ft_substr(s, (unsigned int)i, w_len);
			if (!res[idx])
				return (free_word_array(res, idx));
			idx++;
			i += w_len;
		}
	}
	res[idx] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	if (!extract_words(res, s, c))
		return (NULL);
	return (res);
}

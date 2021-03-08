/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <ztouzri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 14:29:29 by ztouzri           #+#    #+#             */
/*   Updated: 2021/02/09 14:00:14 by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_isin(char const *s, char const c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static	char	*ft_strtrimmer(char const *s, char const c)
{
	size_t	begin;
	size_t	end;

	if (!s)
		return (NULL);
	begin = 0;
	end = ft_strlen(s) - 1;
	while (s[begin] == c)
		begin++;
	while (s[end] == c)
		end--;
	return (ft_substr(s, begin, end - begin + 1));
}

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	wordcount;
	size_t	i;

	if (!s)
		return (0);
	wordcount = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			wordcount++;
			i--;
		}
		i++;
	}
	return (wordcount);
}

static	char	**ft_splitter(char const *s, char c, size_t wordcount)
{
	char	**split;
	size_t	begin;
	size_t	len;
	size_t	n;

	if (!(split = malloc(sizeof(char *) * (wordcount + 1))))
		return (NULL);
	n = 0;
	begin = 0;
	len = 0;
	while (s[begin] && n < wordcount)
	{
		if (s[begin + len] == c || !s[begin + len])
		{
			split[n] = ft_substr(s, begin, len);
			n++;
			while (s[begin + len] == c)
				len++;
			begin += len;
			len = 0;
		}
		len++;
	}
	split[n] = NULL;
	return (split);
}

char			**ft_split(char const *s, char c)
{
	char	**split;
	char	*trimmed;

	if (s == 0)
		return (NULL);
	if (!s || !(trimmed = ft_strtrimmer(s, c)))
	{
		if (!(split = malloc(sizeof(char *))))
			return (NULL);
		split[0] = NULL;
		return (split);
	}
	if (!ft_isin(s, c) && ft_strlen(s) && c)
	{
		free(trimmed);
		if (!(split = malloc(sizeof(char *) * 2)))
			return (NULL);
		split[0] = ft_strdup(s);
		split[1] = NULL;
		return (split);
	}
	split = ft_splitter(trimmed, c, ft_wordcount(trimmed, c));
	free(trimmed);
	return (split);
}

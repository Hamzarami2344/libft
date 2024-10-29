/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 22:58:16 by hrami             #+#    #+#             */
/*   Updated: 2024/10/27 23:04:35 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **arr, int i)
{
	while (i-- > 0)
		free(arr[i]);
	free(arr);
}

static int	count_word(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i])
			count++;
		while (str[i] != c && str[i])
			i++;
	}
	return (count);
}

static char	*ft_str_dup(char const *str, int size)
{
	int		i;
	char	*arr;

	i = 0;
	arr = malloc(size + 1);
	if (!arr)
		return (NULL);
	while (str[i] && i < size)
	{
		arr[i] = str[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

static char	**extract_word(char const *s, char c, char **result)
{
	int	i;
	int	len;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		if (len > 0)
		{
			result[i] = ft_str_dup(s, len);
			if (result[i] == NULL)
			{
				ft_free(result, i);
				return (NULL);
			}
			i++;
		}
		s += len;
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	return (extract_word(s, c, result));
}
// int	main() {
// 	char *arr = "hamza rami";
// 	char **words = ft_split(arr, ' ');
// 	for (int i = 0; words[i] != NULL; i++) 
// 	{
// 		printf("%s\n", words[i]);
// 		free(words[i]);
// 	}
// 	free(words);
// 	return 0;
// }

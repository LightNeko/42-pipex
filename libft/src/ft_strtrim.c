/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:28:40 by znicola           #+#    #+#             */
/*   Updated: 2024/10/13 17:46:06 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	strt_end(size_t *st, size_t *en, char const *s1, char const *set)
{
	while (ft_strchr(set, s1[*st]) || ft_strchr(set, s1[*en]))
	{
		if (ft_strchr(set, s1[*st]))
			(*st)++;
		if (ft_strchr(set, s1[*en]))
			(*en)--;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	st;
	size_t	en;
	char	*arr;

	en = ft_strlen(s1);
	st = 0;
	if (en > 0)
		en--;
	strt_end(&st, &en, s1, set);
	if (st > en)
		arr = ft_substr(s1, st, 0);
	else
		arr = ft_substr(s1, st, en - st + 1);
	return (arr);
}

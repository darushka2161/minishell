/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgwin <tgwin@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:35:14 by tgwin             #+#    #+#             */
/*   Updated: 2022/09/28 10:35:14 by tgwin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, int start, int len)
{
	char	*subs;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
		return ((char *)ft_calloc(1, sizeof(char)));
	if (len > ft_strlen(s + start))
		subs = (char *)ft_calloc(ft_strlen(s + start) + 1, sizeof(char));
	else
		subs = (char *)ft_calloc(len + 1, sizeof(char));
	if (subs == NULL)
		return (NULL);
	if (ft_strlcpy(subs, s + start, len + 1))
		return (subs);
	free(subs);
	return (NULL);
}

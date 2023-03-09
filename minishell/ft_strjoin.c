/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgwin <tgwin@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:34:52 by tgwin             #+#    #+#             */
/*   Updated: 2022/09/28 10:34:52 by tgwin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, char const *s2)
{
	char		*res;
	size_t		len;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	if (*s1 == '\0' && *s2 == '\0')
		return ((char *)ft_calloc(1, sizeof(char)));
	if (*s1 == '\0')
		return (ft_strdup(s2));
	if (*s2 == '\0')
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = (char *)ft_calloc(len, sizeof(char));
	if (res == NULL)
		return (NULL);
	if (ft_strlcpy(res, s1, len) && ft_strlcpy(res + ft_strlen(s1), s2, len))
		return (res);
	free(res);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgwin <tgwin@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:34:48 by tgwin             #+#    #+#             */
/*   Updated: 2022/09/28 10:34:48 by tgwin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	str_len;
	char	*str_dup;

	if (str == NULL)
		return (NULL);
	if (*str == '\0')
		return ((char *)ft_calloc(1, sizeof(char)));
	str_len = ft_strlen(str) + 1;
	str_dup = (char *)ft_calloc(str_len, sizeof(char));
	if (str_dup != NULL)
	{
		if (ft_strlcpy(str_dup, str, str_len))
			return (str_dup);
	}
	return (NULL);
}

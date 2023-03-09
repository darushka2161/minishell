/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgwin <tgwin@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:35:10 by tgwin             #+#    #+#             */
/*   Updated: 2022/09/28 10:35:10 by tgwin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str_1, const char *str_2, size_t n)
{
	const char	*s1;
	const char	*s2;

	if (str_1 == NULL || str_2 == NULL || n == 0)
		return (0);
	s1 = str_1;
	s2 = str_2;
	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0' && n--)
	{
		if (n)
		{
			s1++;
			s2++;
		}
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

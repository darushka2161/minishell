/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinchr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgwin <tgwin@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:34:57 by tgwin             #+#    #+#             */
/*   Updated: 2022/09/28 10:34:57 by tgwin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinchr(char *res, char c)
{
	char	*tmp;

	if (res != NULL && c == 0)
		return (ft_strdup(res));
	if (res == NULL)
		return (ft_memcpy((char *)ft_calloc(2, sizeof(char)), &c, 1));
	tmp = (char *)ft_calloc(ft_strlen(res) + 2, sizeof(char));
	if (tmp != NULL)
	{
		ft_memcpy(tmp, res, ft_strlen(res));
		ft_memcpy(tmp + ft_strlen(res), &c, 1);
	}
	if (tmp != NULL && ft_strlen(tmp) == ft_strlen(res) + 1)
		return (tmp);
	if (tmp != NULL)
		free(tmp);
	return (NULL);
}

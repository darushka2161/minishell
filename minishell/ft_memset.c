/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgwin <tgwin@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:34:23 by tgwin             #+#    #+#             */
/*   Updated: 2022/09/28 10:34:23 by tgwin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int c, size_t l)
{
	unsigned char	*buf_tmp;

	if (!buf)
		return (NULL);
	buf_tmp = (unsigned char *)buf;
	while (l--)
	{
		*buf_tmp++ = (unsigned char)c;
	}
	return (buf);
}

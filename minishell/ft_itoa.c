/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgwin <tgwin@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:34:12 by tgwin             #+#    #+#             */
/*   Updated: 2022/09/28 10:34:12 by tgwin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		i;
	t_ulli	ulln;
	t_ulli	dev;
	char	res[12];

	ft_memset(res, '\0', 12);
	i = 0;
	dev = 10;
	ulln = n;
	if (n < 0)
	{
		res[i++] = '-';
		ulln *= -1;
	}
	while (ulln % dev != ulln)
		dev *= 10;
	while (dev != 1)
	{
		dev /= 10;
		res[i++] = ulln / dev + 48;
		ulln = ulln % dev;
	}
	return (ft_strdup(res));
}

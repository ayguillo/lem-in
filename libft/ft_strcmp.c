/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlambert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:50:47 by vlambert          #+#    #+#             */
/*   Updated: 2019/05/20 12:37:56 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (s1[i] == s2[j])
	{
		if (!(s1[i]))
			return (0);
		i += 1;
		j += 1;
	}
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[j]));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpyfast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlambert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 11:13:33 by vlambert          #+#    #+#             */
/*   Updated: 2019/04/26 16:07:08 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_strcpyfast(char *cpy, const char *s1, size_t i)
{
	while (i >= 8)
	{
		i -= 8;
		*(unsigned long long*)(cpy + i) = *(unsigned long long*)(s1 + i);
	}
	while (i--)
		cpy[i] = s1[i];
}

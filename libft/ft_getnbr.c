/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:35:53 by ayguillo          #+#    #+#             */
/*   Updated: 2019/05/20 13:55:13 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_getnbr(const char *str)
{
	int		i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return ((i == 0 || i > 9) ? 0 : 1);
}
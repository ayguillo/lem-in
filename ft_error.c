/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 11:49:18 by ayguillo          #+#    #+#             */
/*   Updated: 2019/04/12 13:05:43 by vlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "lemin.h"

void	ft_error(char *line, t_all *all)
{
	if (line)
		ft_strdel(&line);
	if (all->map)
		free_chain(all->map, TRUE);
	if (all->str)
		ft_strdel(&(all->str));
	if (all->queue)
		free_chain(all->queue, FALSE);
	ft_putstr_fd("ERROR\n", 2);
	exit(-1);
}

void	ft_del(char *s1, char *s2)
{
	if (s1)
		ft_strdel(&s1);
	if (s2)
		ft_strdel(&s2);
}

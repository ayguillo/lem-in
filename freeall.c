/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freesol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 11:40:12 by ayguillo          #+#    #+#             */
/*   Updated: 2019/04/29 11:52:36 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft/libft.h"
#include <stdlib.h>

void		ft_freet2i(int **i)
{
	if (!(*i))
		return ;
	free(*i);
	*i = NULL;
}

void		ft_freesol(t_sol ***sol)
{
	int i;

	if (!(*sol))
		return ;
	i = 0;
	while ((*sol)[i])
	{
		free((*sol)[i]);
		(*sol)[i] = NULL;
		i++;
	}
	free(*sol);
	(*sol) = NULL;
}

void		ft_freeall(t_room **room, char **name, char ***tmp)
{
	if (name)
		ft_strdel(name);
	if (room)
		free(*room);
	if (tmp)
		ft_free_tab2d(tmp);
}

void		ft_del(char *s1, char *s2)
{
	if (s1)
		ft_strdel(&s1);
	if (s2)
		ft_strdel(&s2);
}

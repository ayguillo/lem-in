/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freesol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 11:40:12 by ayguillo          #+#    #+#             */
/*   Updated: 2019/04/15 11:11:09 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft/libft.h"
#include <stdlib.h>

void			ft_freet2i(int **i)
{
	if (!i)
		return ;
	free(*i);
	*i = NULL;
}

void			ft_freesol(t_sol ***sol)
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

void			ft_freeall(t_room **room, char **name, char ***tmp)
{
	if (room)
		free(*room);
	if (tmp)
		ft_free_tab2d(tmp);
	if (name)
		ft_strdel(name);
}

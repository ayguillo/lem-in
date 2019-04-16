/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:10:18 by ayguillo          #+#    #+#             */
/*   Updated: 2019/04/15 12:15:24 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"

static t_room	*ft_found(t_room *room, int way, t_room *end)
{
	t_room_list	*tmp;
	int			to_start;

	tmp = room->linked;
	to_start = room->to_start;
	while (tmp)
	{
		if (tmp->room->vu == way && to_start < tmp->room->to_start)
			return (tmp->room);
		tmp = tmp->next;
	}
	return (end);
}

static int		ft_lenway(int way, t_room *end)
{
	t_room_list	*tmp;

	tmp = end->linked;
	while (tmp)
	{
		if (tmp->room->vu == way)
			return (tmp->room->to_start);
		tmp = tmp->next;
	}
	return (0);
}

static t_sol	**create_sol(t_all *all)
{
	int		way;
	int		len;
	t_sol	**sol;
	int		i;

	way = all->way;
	if (!(sol = malloc(sizeof(t_sol*) * (way + 1))))
		return (NULL);
	sol[way] = 0;
	way--;
	while (way >= 0)
	{
		if (!(len = ft_lenway(way + 1, all->end)))
			return (NULL);
		if (!(sol[way] = malloc(sizeof(t_sol) * (len + 1))))
			return (NULL);
		i = -1;
		while (++i <= len)
		{
			sol[way][i].ant = 0;
			sol[way][i].len = len;
		}
		way--;
	}
	return (sol);
}

t_sol			**ft_fill(t_all *all, t_sol **sol, t_room *start, t_room *end)
{
	int		way;
	int		i;
	t_room	*room;

	way = all->way;
	if (!(sol = create_sol(all)))
		return (NULL);
	way--;
	while (way >= 0)
	{
		room = start;
		i = 0;
		while (room != end)
		{
			room = ft_found(room, way + 1, end);
			sol[way][i].name = room->name;
			sol[way][i].ant = 0;
			i++;
		}
		way--;
	}
	return (sol);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlambert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 08:28:04 by vlambert          #+#    #+#             */
/*   Updated: 2019/04/19 15:47:31 by vlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room_list	*thread(t_room_list *queue, t_room *room)
{
	t_room_list *tmp;

	tmp = queue;
	while (tmp && tmp->room)
		tmp = tmp->next;
	if (!tmp)
		queue = add_room(queue, room, FALSE);
	else
		tmp->room = room;
	return (queue);
}

t_room		*unqueue(t_room_list *queue)
{
	t_room_list *tmp;
	t_room		*ret;

	tmp = queue;
	ret = queue->room;
	while (tmp->room && tmp->next)
	{
		tmp->room = tmp->next->room;
		tmp = tmp->next;
	}
	tmp->room = 0;
	return (ret);
}

void		save_way(t_room *end, t_room *start, int way)
{
	t_room_list *tmp;

	tmp = end->linked;
	while (tmp)
	{
		if (tmp->room != start && tmp->room->vu == -way
				&& tmp->room->to_start == end->to_start - 1)
		{
			tmp->room->vu = way;
			save_way(tmp->room, start, way);
			return ;
		}
		tmp = tmp->next;
	}
}

int			success(t_room_list *queue, t_all *all, t_room *end, int way)
{
	t_room_list *clean;

	clean = queue;
	while (clean && clean->room)
	{
		clean->room = 0;
		clean = clean->next;
	}
	save_way(end, all->start, way);
	return (end->to_start);
}

int			bfs(t_room *room, t_room *end, int way, t_all *all)
{
	t_room_list *tmp;

	if (!room || !(all->queue = thread(all->queue, room)))
		ft_error(0, all);
	room->vu = -way;
	while (all->queue && all->queue->room)
	{
		room = unqueue(all->queue);
		tmp = room->linked;
		while (tmp)
		{
			if (tmp->room != all->start && tmp->room->vu != -way
					&& tmp->room->vu <= 0)
			{
				tmp->room->to_start = room->to_start + 1;
				if (tmp->room == end)
					return (success(all->queue, all, end, way));
				if (!(all->queue = thread(all->queue, tmp->room)))
					ft_error(0, all);
				tmp->room->vu = -way;
			}
			tmp = tmp->next;
		}
	}
	return (0);
}

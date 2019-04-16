/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlambert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:29:39 by vlambert          #+#    #+#             */
/*   Updated: 2019/04/15 16:32:43 by vlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "lemin.h"
#include <stdlib.h>

t_room		*find_room(char *name, t_room_list *list)
{
	t_room_list *temp;

	temp = list;
	while (temp)
	{
		if (!(ft_strcmp(temp->room->name, name)))
			return (temp->room);
		temp = temp->next;
	}
	return (NULL);
}

t_room_list	*ft_verif(t_room_list *map, t_room *room, t_room_list *temp)
{
	if (!(ft_strcmp(room->name, temp->room->name))
			|| (room->coord[X] == temp->room->coord[X]
				&& room->coord[Y] == temp->room->coord[Y])
			|| (room->state != 0 && room->state == temp->room->state))
		return (free_chain(map, TRUE));
	return (map);
}

t_room_list	*add_room(t_room_list *list, t_room *room, int verif)
{
	t_room_list *temp;
	t_room_list *new;

	temp = list;
	if (temp && verif && !(ft_verif(list, room, temp)))
		return (NULL);
	while (temp && temp->next)
	{
		temp = temp->next;
		if (verif && !(ft_verif(list, room, temp)))
			return (NULL);
	}
	if (!(new = malloc(sizeof(t_room_list))))
		return (free_chain(list, FALSE));
	new->room = room;
	new->next = NULL;
	if (temp)
		temp->next = new;
	else
		list = new;
	return (list);
}

t_room_list	*free_chain(t_room_list *list, int final)
{
	t_room_list *to_free;

	while (list)
	{
		if (final == TRUE)
		{
			if (list->room->name)
				free(list->room->name);
			free_chain(list->room->linked, FALSE);
			if (list->room)
				free(list->room);
		}
		to_free = list;
		list = list->next;
		free(to_free);
	}
	return (list);
}

void		finish(t_all *all)
{
	ft_printfinal(all, all->bestway, all->ants, all->sol);
	ft_strdel(&(all->str));
	free_chain(all->queue, FALSE);
	free_chain(all->map, TRUE);
	ft_freesol(&(all->sol));
}

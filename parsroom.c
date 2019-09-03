/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsroom.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 11:45:43 by ayguillo          #+#    #+#             */
/*   Updated: 2019/05/20 14:28:46 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdlib.h>
#include "libft/libft.h"

static int		create_room(char **tab, t_room *room)
{
	room->name = NULL;
	if (tab[0][0] == 'L' || (ft_strchr(tab[0], '-')))
		return (0);
	if (!(room->name = ft_strdup(tab[0])))
		return (0);
	room->coord[X] = ft_atoi(tab[1]);
	room->coord[Y] = ft_atoi(tab[2]);
	room->linked = NULL;
	room->to_start = 0;
	room->vu = 0;
	return (1);
}

static t_room	*ft_startend(char *str, t_room *room, t_all *all)
{
	if (!all->start && room->state == OTHER && !(ft_strcmp(str, "##start")))
	{
		room->state = START;
		all->start = room;
	}
	else if (!all->end && room->state == OTHER && !(ft_strcmp(str, "##end")))
	{
		room->state = END;
		all->end = room;
	}
	return (room);
}

static int		ft_create(char *line, t_all *all, t_room *room)
{
	char	**tmp;

	tmp = NULL;
	if (!(tmp = ft_strsplit(line, ' ')))
		return (0);
	if (ft_raws_nbr(tmp) != 3)
	{
		if (room->state == START)
			all->start = 0;
		if (room->state == END)
			all->end = 0;
		ft_freeall(&room, NULL, &tmp);
		if (!(ft_parsepipe(&line, all)))
			return (0);
		return (1);
	}
	if (!create_room(tmp, room) || !(all->map = add_room(all->map, room, TRUE)))
	{
		ft_freeall(&room, &(room->name), &tmp);
		return (0);
	}
	ft_free_tab2d(&tmp);
	return (2);
}

static int		ft_createmap(char **line, t_all *all, int retgnl)
{
	int		ret;
	t_room	*room;

	if (!(room = malloc(sizeof(t_room))))
		return (0);
	room->state = OTHER;
	while (retgnl > 0 && *line[0] == '#')
	{
		room = ft_startend(*line, room, all);
		all->str = ft_strjoinwtn(&(all->str), line, retgnl);
		retgnl = ft_gnl(0, line);
	}
	if (retgnl > 0 && *line[0] != '#')
	{
		ret = ft_create(*line, all, room);
		if (ret == 2)
			all->str = ft_strjoinwtn(&(all->str), line, retgnl);
		return (ret);
	}
	return (2);
}

int				ft_parsroom(t_all *all)
{
	char			*l;
	int				ret;

	l = NULL;
	if ((ret = ft_gnl(0, &l)) <= 0)
		ft_error(l, all);
	while (ret > 0 && l[0] == '#')
	{
		all->str = ft_strjoinwtn(&(all->str), &l, ret);
		ret = ft_gnl(0, &l);
	}
	if (!l || l[0] == 0 || ft_getnbr(l) != 1 || ((all->ants) = ft_atoi(l)) <= 0)
		ft_error(l, all);
	all->str = ft_strjoinwtn(&(all->str), &l, ret);
	ret = ft_gnl(0, &l);
	while (ret > 0)
	{
		if (!(ret = ft_createmap(&l, all, ret)))
			ft_error(l, all);
		else if (ret == 1)
			return (1);
		ret = ft_gnl(0, &l);
	}
	ft_error(l, all);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlambert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 09:38:58 by vlambert          #+#    #+#             */
/*   Updated: 2019/04/15 16:39:20 by vlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft/libft.h"
#include <stdlib.h>

static void	init(t_all *all)
{
	all->map = NULL;
	all->ants = 0;
	all->str = ft_strnew(0);
	all->end = NULL;
	all->start = NULL;
	all->map_size = 0;
	all->tab = NULL;
	all->new_score = 0.0;
	all->sol = NULL;
	all->queue = NULL;
	all->best_score = 0.0;
	all->way = 1;
	all->bestway = 1;
	all->endants = 1;
}

static void	clean_vu(t_room_list *map)
{
	t_room_list *tmp;

	tmp = map;
	while (tmp)
	{
		tmp->room->vu = 0;
		tmp = tmp->next;
	}
}

static int	oneway(t_room *start, t_all *all)
{
	t_room_list *tmp;

	tmp = NULL;
	if (!start)
		return (1);
	tmp = start->linked;
	while (tmp)
	{
		if (tmp->room == all->end)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static void	testways(t_all *all, t_room_list *tmp)
{
	int		ret;

	clean_vu(all->map);
	all->way = 1;
	tmp->room->to_start = 1;
	if ((all->new_score = all->ants + (double)bfs(tmp->room,
					all->end, all->way, all)) > (double)all->ants)
	{
		while ((ret = bfs(all->start, all->end, (all->way += 1), all)) > 0)
		{
			all->new_score = (all->new_score * (double)(all->way - 1)
					+ (double)ret) / (double)all->way;
			if (all->new_score < all->best_score)
			{
				if (all->sol)
					ft_freesol(&(all->sol));
				all->best_score = all->new_score;
				all->bestway = all->way;
				all->sol = ft_fill(all, all->sol, all->start, all->end);
			}
		}
		if (ret < 0)
			ft_error(0, all);
	}
}

int			main(void)
{
	t_all		all;
	t_room_list	*tmp;

	init(&all);
	ft_parsroom(&all);
	if (all.end)
		all.end->col = all.map_size - 1;
	if (!(oneway(all.start, &all)))
	{
		ft_printoneway(all.ants, all.end, &all);
		return (1);
	}
	if (!(all.end) || !(all.start)
			|| (all.best_score = all.ants
				+ bfs(all.start, all.end, all.way, &all)) <= all.ants)
		ft_error(0, &all);
	all.sol = ft_fill(&all, all.sol, all.start, all.end);
	ft_printf("%s\n", all.str);
	tmp = all.start->linked;
	while (tmp)
	{
		testways(&all, tmp);
		tmp = tmp->next;
	}
	finish(&all);
}

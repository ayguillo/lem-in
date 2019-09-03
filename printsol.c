/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printsol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 11:39:59 by ayguillo          #+#    #+#             */
/*   Updated: 2019/04/15 16:37:13 by vlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdlib.h>

static int		*distribute(t_sol **sol, int way, int ants)
{
	int		*nb_ants;
	double	n;
	int		diff;
	int		i;

	if (!(nb_ants = (int *)malloc(sizeof(int) * (way + 1))))
		return (NULL);
	nb_ants[way] = 0;
	way--;
	while (way >= 0)
	{
		i = -1;
		diff = 0;
		while (++i <= way)
			diff += sol[way][0].len - sol[i][0].len;
		n = (double)(ants - diff) / (double)(way + 1);
		if (n > (double)(int)n)
			nb_ants[way] = (int)n + 1;
		else
			nb_ants[way] = (int)n;
		ants -= nb_ants[way];
		way--;
	}
	return (nb_ants);
}

static void		ft_dispatch(t_all *all, int *ants, t_sol *sol, int *antsway)
{
	int		j;
	int		len;
	int		k;

	len = sol[0].len;
	j = len;
	k = j - 1;
	while (j >= 1)
	{
		if (sol[k].ant)
			ft_printline(all, antsway, j, sol);
		else
			sol[j].ant = sol[k].ant;
		k--;
		j--;
	}
	if (*antsway)
		ft_printfirstline(sol, ants, all, antsway);
	else
		sol[0].ant = 0;
}

void			ft_printfinal(t_all *all, int way, int antstot, t_sol **sol)
{
	int		*antsway;
	int		ants;
	int		end;
	int		i;

	ants = 1;
	end = 1;
	if (!sol)
		return ;
	if (!(antsway = distribute(sol, way, antstot)))
		return ;
	way--;
	while (all->endants <= antstot)
	{
		i = 0;
		while (i <= way)
		{
			ft_dispatch(all, &ants, sol[i], antsway + i);
			i++;
		}
	}
	ft_freet2i(&antsway);
}

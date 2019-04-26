/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printline.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 11:34:13 by ayguillo          #+#    #+#             */
/*   Updated: 2019/04/19 16:13:59 by vlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft/libft.h"
#include <stdlib.h>

void	ft_printfirstline(t_sol *sol,
		int *ants, t_all *all, int *antsway)
{
	sol[0].ant = *ants;
	if (sol == all->sol[all->bestway - 1])
		ft_printf("L%i-%s\n", sol[0].ant, sol[0].name);
	else
		ft_printf("L%i-%s ", sol[0].ant, sol[0].name);
	(*antsway)--;
	(*ants)++;
}

void	ft_printline(t_all *all, int *antsway, int j, t_sol *sol)
{
	int		k;
	char	*name;

	k = j - 1;
	name = all->end->name;
	if ((!(ft_strcmp(name, sol[j].name))))
		all->endants += 1;
	sol[j].ant = sol[k].ant;
	if (sol == all->sol[all->bestway - 1] && ((k - 1 < 0 && !(*antsway))
				|| (k - 1 >= 0 && !(sol[k - 1].ant))))
		ft_printf("L%i-%s\n", sol[j].ant, sol[j].name);
	else
		ft_printf("L%i-%s ", sol[j].ant, sol[j].name);
}

void	ft_printoneway(int ants, t_room *end, t_all *all)
{
	int		i;
	char	*nameend;

	i = 1;
	nameend = end->name;
	ft_printf("%s\n", all->str);
	while (i <= ants)
	{
		if (i != ants)
			ft_printf("L%i-%s ", i, nameend);
		else
			ft_printf("L%i-%s\n", i, nameend);
		i++;
	}
	free_chain(all->map, TRUE);
	free(all->str);
}

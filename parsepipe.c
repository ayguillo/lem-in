/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsepipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlambert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 11:49:26 by vlambert          #+#    #+#             */
/*   Updated: 2019/04/15 12:22:20 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "lemin.h"
#include <stdlib.h>

char		*ft_strjoinwtn(char *s1, char *s2, int ret)
{
	char			*s3;
	static size_t	size;
	size_t			i;
	int				j;

	if (!s1 && !s2)
		return (NULL);
	if (!(size))
		size = ft_strlen(s1) + ret + 2;
	else
		size = size + ret + 1;
	if (!(s3 = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	j = ret + 2;
	i = size - j;
	ft_strcpyfast(s3, s1, i);
	ft_strcpyfast(s3 + i, s2, ret + 1);
	s3[size - 2] = '\n';
	s3[size - 1] = '\0';
	ft_del(s1, s2);
	return (s3);
}

static int	add_link(t_room *room1, t_room *room2)
{
	if (find_room(room1->name, room2->linked))
		return (1);
	if (!(room1->linked = add_room(room1->linked, room2, FALSE))
			|| !(room2->linked = add_room(room2->linked, room1, FALSE)))
		return (0);
	return (1);
}

static int	free_ret(char ***split, char **line, int ret)
{
	if (split && *split)
		ft_free_tab2d(split);
	if (line && *line)
		ft_strdel(line);
	return (ret);
}

int			ft_parsepipe(char *line, t_all *all)
{
	char		**split;
	t_room		*room1;
	t_room		*room2;
	int			ret;

	ret = 1;
	while (line && ret > 0)
	{
		if (line[0] != '#')
		{
			if (!(split = ft_strsplit(line, '-')))
				return (free_ret(0, &line, 0));
			if (ft_raws_nbr(split) != 2
					|| !(room1 = find_room(split[0], all->map))
					|| !(room2 = find_room(split[1], all->map)))
				return (free_ret(&split, &line, 1));
			ft_free_tab2d(&split);
			if (!(add_link(room1, room2)))
				return (free_ret(0, &line, 0));
		}
		ret == 1 ? (all->str = ft_strjoinwtn(all->str, line, ft_strlen(line)))
			: (all->str = ft_strjoinwtn(all->str, line, ret));
		ret = ft_gnl(0, &line);
	}
	return (free_ret(0, &line, 1));
}

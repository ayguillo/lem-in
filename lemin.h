/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlambert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 09:43:26 by vlambert          #+#    #+#             */
/*   Updated: 2019/05/20 14:14:21 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# define X 0
# define Y 1
# define TRUE 1
# define FALSE 0
# define END 2
# define START 1
# define OTHER 0
# define FULL 1
# define EMPTY 0

struct s_room_list;
struct s_room;

typedef struct s_room_list	t_room_list;
typedef struct s_room		t_room;

struct						s_room
{
	t_room_list				*linked;
	char					*name;
	int						vu;
	int						to_start;
	int						state;
	int						coord[2];
};

struct						s_room_list
{
	t_room_list				*next;
	t_room					*room;
};

typedef struct				s_tab
{
	char					*name;
	int						way;
	int						dir;
}							t_tab;

typedef struct				s_sol
{
	char					*name;
	int						ant;
	int						len;
}							t_sol;

typedef struct				s_all
{
	double					new_score;
	double					best_score;
	t_room_list				*map;
	t_room_list				*queue;
	int						way;
	char					*str;
	t_sol					**sol;
	int						ants;
	t_room					*start;
	t_room					*end;
	int						endants;
	int						bestway;
}							t_all;

int							ft_parsepipe(char **line, t_all *all);
t_room						*find_room(char *name, t_room_list *list);
t_room_list					*add_room(t_room_list *list, t_room *room, int ver);
int							ft_parsroom(t_all *all);
t_room_list					*free_chain(t_room_list *list, int fin);
void						ft_error(char *line, t_all *all);
char						*ft_strjoinwtn(char **s1, char **s2, int ret);
void						ft_del(char **s1, char **s2);
int							bfs(t_room *room, t_room *end, int way, t_all *all);
t_sol						**ft_fill(t_all *all, t_sol **sol, t_room *start,
		t_room*end);
void						ft_freesol(t_sol ***sol);
void						ft_freet2i(int **i);
void						ft_freeall(t_room **room, char **name, char ***tmp);
void						ft_printfinal(t_all *all, int way, int antstot,
		t_sol **sol);
void						ft_printfirstline(t_sol *sol, int *ants, t_all *all,
		int *antsway);
void						ft_printline(t_all *all, int *antsway,
		int j, t_sol *sol);
void						ft_printoneway(int ants, t_room *end, t_all *all);
void						finish(t_all *all);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 13:32:25 by juazouz           #+#    #+#             */
/*   Updated: 2019/01/28 18:35:26 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

/*
**	Includes.
*/

# include "libft.h"

/*
**	Defines.
*/

/*
**	Types.
*/

typedef	struct s_point		t_point;
typedef	struct s_lem_in		t_lem_in;
typedef	struct s_room		t_room;
typedef	enum e_roomtype		t_roomtype;
typedef	struct s_move		t_move;
typedef struct s_round		t_round;
typedef struct s_solution	t_solution;

struct	s_point
{
	int	x;
	int	y;
};

enum	e_roomtype
{
	standard,
	start,
	end,
};

struct	s_lem_in
{
	int		total_ants;
	t_room	*start;
	t_room	*end;
	t_list	*rooms;
};

struct	s_room
{
	char		*name;
	t_roomtype	type;
	t_point		pos;
	int			ants;
	t_list		*links;
};

/*
**	Final result.
**	Contains a list of rounds.
*/

struct	s_solution
{
	t_list	*rounds;
};

/*
**	Round.
**	Contains a list of moves.
*/

struct	s_round
{
	t_list	*moves;
};

/*
**	Ant move going from origin to target.
*/

struct	s_move
{
	t_room	*origin;
	t_room	*target;
};

/*
**	Core.
*/

void	lem_in_init(t_lem_in *lem_in);
void	lem_in_add_room(t_lem_in *lem_in, t_room *room);
void	lem_in_free(t_lem_in *lem_in);
void	lem_in_die();

/*
**	Parse.
*/

void	parse(t_lem_in *lem_in);
void	parse_ants_count(t_lem_in *lem_in, char **line);
void	parse_rooms(t_lem_in *lem_in, char **line);
void	parse_links(t_lem_in *lem_in, char **line);

/*
**	Room.
*/

t_room	*room_new(char *name, t_roomtype type, int x, int y);
t_room	*room_find_by_name(t_lem_in *lem_in, char *name);
void	room_add_link(t_lem_in *lem_in, char *origin, char *target);
void	room_set_ants(t_room *room, int ants);
void	room_free(void *content, size_t size);

/*
**	Solve.
*/

void	solve(t_lem_in *lem_in, t_solution *solution);

/*
**	Solution.
*/

void	print_solution(t_solution *solution);

/*
**	Utils.
*/

void	ft_free_tab(char ***tab);
int		ft_strindex(const char *hay, char c);
int		ft_strrindex(const char *hay, char c);

#endif

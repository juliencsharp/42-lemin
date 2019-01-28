/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 13:32:25 by juazouz           #+#    #+#             */
/*   Updated: 2019/01/28 16:09:29 by agoulas          ###   ########.fr       */
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

typedef	struct s_point	t_point;
typedef	struct s_lem_in	t_lem_in;
typedef	struct s_room	t_room;
typedef	enum e_roomtype	t_roomtype;

struct	s_point
{
	int	x;
	int	y;
};

struct	s_lem_in
{
	int		total_ants;
	t_room	*start;
	t_room	*end;
	t_list	*rooms;
};

typedef struct	s_room
{
	char		*name;
	t_roomtype	type;
	t_point		pos;
	int			ants;
	t_list		*links;
};

enum	e_roomtype
{
	standard,
	start,
	end,
};

/*
**	Core.
*/

/*
**	Parse.
*/

void	parse(t_lem_in *lem_in);
void	parse_ants_count(t_lem_in *lem_in);
void	parse_rooms(t_lem_in *lem_in);
void	parse_links(t_lem_in *lem_in);

/*
**	Room.
*/

t_room	*room_new(char *name, t_roomtype type, int x, int y);
t_room	*room_add_link(t_room *room);
void	room_set_ants(t_room *room, int ants);
t_room	room_free(t_room *room);

/*
**	Functions.
*/

#endif

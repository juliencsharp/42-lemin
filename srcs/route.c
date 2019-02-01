/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:54:42 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/01 16:36:27 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	to DO: Optimize (avoid duplicate tests)
*/

void		route_create_conflicts_map(t_route *route, t_glist *routes)
{
	t_glist	*curr;
	t_bool	conflict;

	curr = routes;
	while (curr != NULL)
	{
		conflict = route_cmp_conflit(curr->route, route);
		if (conflict)
			bitmap_set(route->conflicts, curr->route->id_route);
		curr = curr->next;
	}
}

/*
** Function for test if the route a is egale to  route b
*/

t_bool		route_equals(t_route *route_a, t_route *route_b)
{
	if (route_a == route_b)
		return (true);
	return (false);
}

/*
** Function test if there are conflict on the two route
*/

t_bool		route_cmp_conflit(t_route *route_a, t_route *route_b)
{
	t_glist	*lst_a;
	t_glist	*lst_b;
	t_room	*room_a;
	t_room	*room_b;

	lst_a = route_a->rooms;
	lst_b = route_b->rooms;
	while (lst_a && lst_a->content)
	{
		room_a = lst_a->content;
		while (room_a && lst_b && lst_b->content)
		{
			room_b = lst_b->content;
			if (room_a->name == room_b->name
					&& room_a->type == standard
					&& room_b->type == standard)
				return (true);
			lst_b = lst_b->next;
		}
		lst_a = lst_a->next;
	}
	return (false);
}

t_bool		route_has_conflict(t_route *a, t_route *b)
{
	t_bool	res;

	res = bitmap_get(a->conflicts, b->id_route);
	return (res);
}

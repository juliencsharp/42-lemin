/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_opt_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:51:25 by agoulas           #+#    #+#             */
/*   Updated: 2019/02/20 15:42:47 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Prints the specified group information.
*/

void	group_print_extra(t_group *group)
{
	t_glist	*curr;

	curr = group->routes;
	ft_fprintf(2, " __________________________________________________\n");
	ft_fprintf(2, "|                                                  |\n");
	ft_fprintf(2, "Group:                                              \n\n");
	ft_fprintf(2, "nb of routes : %d\n", group->count);
	ft_fprintf(2, "minimun size of routes : %d\n", group->low_len);
	ft_fprintf(2, "maximun size of routes : %d\n", group->high_len);
	while (curr != NULL)
	{
		ft_fprintf(2, "	");
		route_print(curr->route);
		curr = curr->next;
	}
	ft_fprintf(2, "|__________________________________________________|\n\n");
}

/*
**	Prints the specified route.
**	Debug purposes.
*/

void	route_print_extra(t_route *route)
{
	ft_fprintf(2, "Route #%d | length: %d |\t", route->id_route, route->len);
	print_nodes(route->rooms);
}

/*
**	Prints the specified room information.
*/

void	room_print_extra(t_room *room)
{
	ft_fprintf(2, " %s :\n", room->name);
	ft_fprintf(2, "	point = {%d,", room->pos.x);
	ft_fprintf(2, " %d}.\n", room->pos.y);
	ft_fprintf(2, "	nb_links = %d.\n", room->links_count);
	ft_fprintf(2, "	nb_type = ");
	if (room->type == standard)
		ft_fprintf(2, "standard\n");
	else
	{
		if (room->type == start)
			ft_fprintf(2, "start\n");
		else
			ft_fprintf(2, "end\n");
	}
	ft_fprintf(2, "	ants = %d.\n", room->ants);
}

/*
**	Prints all rooms information.
*/

void	lem_in_print_all_rooms(t_lem_in *lem_in)
{
	t_glist *curr;

	curr = lem_in->rooms;
	ft_fprintf(2, "\n");
	ft_fprintf(2, "		Print_rooms\n");
	ft_fprintf(2, "length = %d\n\n", lem_in->room_len);
	while (curr != NULL)
	{
		room_print_extra(curr->room);
		curr = curr->next;
	}
	ft_fprintf(2, " \n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:50:22 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/05 18:28:26 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Builds a solution or a set of moves using the specified group.
*/

void	build_solution(t_solution *solution, t_group *group, int total_ants)
{
	int	ants_left;
	int	*maps;

	maps = ft_memalloc(group->count * sizeof(int*));

}

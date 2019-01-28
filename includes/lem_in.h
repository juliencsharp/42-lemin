/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 13:32:25 by juazouz           #+#    #+#             */
/*   Updated: 2019/01/28 13:22:53 by juazouz          ###   ########.fr       */
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

typedef	struct s_lem_in	t_lem_in;
typedef	struct s_room	t_room;
typedef	struct s_point	t_point;

struct	s_lem_in
{
	int		total_ants;
	t_room	*start;
	t_room	*end;
};

struct	s_room
{
	char	*name;
	t_point	pos;
	int		ants;
	t_list	*links;
};

struct s_point
{
	int	x;
	int	y;
};


/*
**	Core.
*/

/*
**	Functions.
*/

#endif

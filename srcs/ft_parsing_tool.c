/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_tool.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 09:59:35 by agoulas           #+#    #+#             */
/*   Updated: 2019/01/28 15:31:45 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_free_tab(char ***tab)
{
	int i;

	i = 0;
	if (*tab == NULL)
		return ;
	while ((*tab)[i] != NULL)
	{
		free((*tab)[i]);
		(*tab)[i] = NULL;
		i++;
	}
	free(*tab);
	*tab = NULL;
}

void	die()
{
	ft_putendl("ERROR");
	exit(EXIT_FAILURE);
}

int		ft_find_carac(const char *hay, char c)
{
	int i;

	i = 0;
	while (hay && hay[i] != '\0')
	{
		if (hay[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_find_last(const char *hay, char c)
{
	int i;

	i = ft_strlen(hay);
	while (i >= 0)
	{
		if (hay[i] == c)
			return (i);
		i--;
	}
	return (-1);
}

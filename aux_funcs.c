/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 21:52:44 by eshor             #+#    #+#             */
/*   Updated: 2020/01/16 19:15:30 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	ft_mod(int a)
{
	return (a < 0 ? -a : a);
}

int		ft_sqrt(int nbr)
{
	int result;

	result = 1;
	while (result * result < nbr)
		result++;
	return (result);
}

void	lst_rev(t_lst **head, int fd)
{
	t_lst *temp;

	temp = *head;
	*head = (*head)->next;
	free(temp->coords);
	free(temp);
	lst_reverse(head);
	close(fd);
}

int		ar_length(char **tetri)
{
	int i;

	i = 0;
	while (tetri[i])
	{
		i++;
	}
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <mbrogg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 18:26:29 by mbrogg            #+#    #+#             */
/*   Updated: 2020/01/04 19:40:48 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_lst	*lst_new(int counter)
{
	t_lst	*res;
    int     i;

    i = -1;
	if (!(res= (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	res->index_number = counter;
    if (!(res->coords = (short *)malloc(sizeof(short) * 8)))
        return (NULL);
    while (++i < 8)
        res->coords[i] = 0;
	res->next = NULL;
	return (res);
}

int 	lst_push_front(t_lst **head, t_lst *new)
{
    if (!new)
        return (0);
	if (*head)
        new->next = *head;
    *head = new;
    return (1);
}

void    lst_rec(t_lst *current)
{
    if (current)
    {
        lst_rec(current->next);
        free(current->coords);
        free(current);
    }
}

void	lst_del(t_lst **head)
{
	if (head && *head)
	{
		lst_rec(*head);
        *head = NULL;
	}
}

void    lst_print(t_lst *head)
{
    int     i;

    i = -1;
    while(head)
    {
        i = -1;
        ft_putnbr(head->index_number);
        ft_putstr("\t->\t");
        while (++i < 4)
        {
            ft_putnbr(head->coords[i]);
            ft_putstr("\t");
        }
        printf("%d %d %d\n", head->l, head->r, head->deep);
        // ft_putnbr(head->l);
        // ft_putstr("\t\b");
        // ft_putnbr(head->r);
        // ft_putstr("\t\b");
        // ft_putnbr(head->deep);
        // ft_putstr("\t\b");
        
        // ft_putnbr(head->index_number);
        // ft_putstr("\t\b");
        // ft_putnbr(head->upperleft);
        ft_putchar('\n');
        head = head->next;
    }
}
    
void    lst_reverse(t_lst **head)
{
    t_lst   *prev;
    t_lst   *cur;
    t_lst   *next;

    prev = NULL;
    cur = NULL;
    next = *head;
    while (next)
    {
        cur = next;
        next = next->next;
        cur->next = prev;
        prev = cur;
    }
    *head = cur;
}

void    lst_foreach(t_lst *head, void (*f)(void *))
{
    t_lst	*current;

	current = head;
	while (current)
	{
		(*f)(&(current->coords));
		current = current->next;
	}
}

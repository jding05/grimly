/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 11:52:38 by sding             #+#    #+#             */
/*   Updated: 2018/04/13 11:52:42 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

t_node	*create_node(int y, int x)
{
	t_node	*new;

	new = ft_memalloc(sizeof(t_node));
	new->y = y;
	new->x = x;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_queue	*create_queue(void)
{
	t_queue	*new;

	new = ft_memalloc(sizeof(t_queue));
	new->front = NULL;
	new->rear = NULL;
	return (new);
}

t_node	*enqueue(t_queue **queue, int x, int y)
{
	t_node	*new;

	if (!queue || !(*queue))
		return (0);
	new = create_node(x, y);
	if (!((*queue)->front))
		(*queue)->front = new;
	if (!((*queue)->rear))
		(*queue)->rear = new;
	else
	{
		(*queue)->rear->next = new;
		new->prev = (*queue)->rear;
		(*queue)->rear = new;
	}
	return (new);
}

t_node	*dequeue(t_queue **queue)
{
	t_node	*tmp;

	if (!queue || !(*queue))
		return (0);
	if ((*queue)->front->next)
	{
		(*queue)->front->next->prev = NULL;
		tmp = (*queue)->front;
		(*queue)->front = (*queue)->front->next;
		tmp->next = NULL;
		if ((*queue)->front->next == NULL)
			(*queue)->rear = (*queue)->front;
		free(tmp);
	}
	else
	{
		free((*queue)->front);
		(*queue)->front = NULL;
		(*queue)->rear = NULL;
	}
	return ((*queue)->front);
}

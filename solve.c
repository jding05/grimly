/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 13:48:15 by sding             #+#    #+#             */
/*   Updated: 2018/04/13 13:48:16 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

int		is_empty(char c, t_input *input)
{
	if (c == input->empty)
		return (1);
	return (0);
}

void	put_direction(char **maze, t_node *spot, t_queue **q, t_input *input)
{
	if (spot->y > 0 && is_empty(maze[spot->y - 1][spot->x], input))
	{
		maze[spot->y - 1][spot->x] = UP;
		enqueue(q, spot->y - 1, spot->x);
	}
	if (spot->x > 0 && is_empty(maze[spot->y][spot->x - 1], input))
	{
		maze[spot->y][spot->x - 1] = LEFT;
		enqueue(q, spot->y, spot->x - 1);
	}
	if (spot->x < input->width && is_empty(maze[spot->y][spot->x + 1], input))
	{
		maze[spot->y][spot->x + 1] = RIGHT;
		enqueue(q, spot->y, spot->x + 1);
	}
	if (spot->y < input->height && is_empty(maze[spot->y + 1][spot->x], input))
	{
		maze[spot->y + 1][spot->x] = DOWN;
		enqueue(q, spot->y + 1, spot->x);
	}
}

int		is_exit(char c, t_input *input)
{
	if (c == input->exit_spot)
		return (1);
	return (0);
}

/*
** check four directions, up, left, down, right
*/

int		check_exit(char **maze, t_node *s, t_input *input)
{
	if ((s->y > 0 && is_exit(maze[s->y - 1][s->x], input)) ||
		(s->x > 0 && is_exit(maze[s->y][s->x - 1], input)) ||
		(s->y < input->height - 1 && is_exit(maze[s->y + 1][s->x], input)) ||
		(s->x < input->width - 1 && is_exit(maze[s->y][s->x + 1], input)))
		return (1);
	return (0);
}

int		solve_maze(char **maze, t_input *input)
{
	t_queue	*q;
	t_node	*spot;
	int		i;

	i = 0;
	q = create_queue();
	enqueue(&q, input->pos[0], input->pos[1]);
	while (q->front)
	{
		spot = q->front;
		if (check_exit(maze, spot, input))
		{
			print_path(maze, spot, input);
			delete_direction(maze, input);
			while (q->front)
				dequeue(&q);
			free(q);
			return (1);
		}
		put_direction(maze, spot, &q, input);
		dequeue(&q);
		i++;
	}
	free(q);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 12:22:55 by sding             #+#    #+#             */
/*   Updated: 2018/04/14 12:22:56 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

void	print_path(char **maze, t_node *spot, t_input *input)
{
	char	direction;

	while (maze[spot->y][spot->x] != input->entrance)
	{
		direction = maze[spot->y][spot->x];
		input->steps++;
		maze[spot->y][spot->x] = input->path;
		if (direction == DOWN)
			spot->y--;
		else if (direction == RIGHT)
			spot->x--;
		else if (direction == UP)
			spot->y++;
		else if (direction == LEFT)
			spot->x++;
	}
}

void	delete_direction(char **maze, t_input *input)
{
	int	i;
	int	j;

	j = 0;
	while (j < input->height)
	{
		i = 0;
		while (maze[j][i])
		{
			if (maze[j][i] == UP || maze[j][i] == LEFT ||
				maze[j][i] == RIGHT || maze[j][i] == DOWN)
				maze[j][i] = input->empty;
			i++;
		}
		j++;
	}
}

void	print_first_line(t_input *input)
{
	ft_putnbr(input->height);
	ft_putchar('x');
	ft_putnbr(input->width);
	ft_putchar(input->block);
	ft_putchar(input->empty);
	ft_putchar(input->path);
	ft_putchar(input->entrance);
	ft_putcharl(input->exit_spot);
}

void	print_queue(t_queue *queue, char order)
{
	t_node	*buf;

	ft_putstr("queue in order :");
	ft_putcharl('R');
	if (!queue || !(queue->rear))
	{
		ft_putstrl("empty queue");
		ft_putchar(order);
		return ;
	}
	buf = order == 'R' ? queue->front : queue->rear;
	while (buf)
	{
		ft_putstr("y: ");
		ft_putnbr(buf->y);
		ft_putstr(" x: ");
		ft_putnbrl(buf->x);
		buf = order == 'R' ? buf->prev : buf->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maze.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 11:49:52 by sding             #+#    #+#             */
/*   Updated: 2018/04/14 11:49:53 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

int		check_map_size(char *str, t_input *input)
{
	int	i;

	i = -1;
	while (str[i + 1])
	{
		if (str[i + 1 + input->width] == '\n')
		{
			if (str[i + 2 + input->width] != '\0')
				i += input->width + 1;
			else if (str[i + 2 + input->width] == '\0')
			{
				if ((i + 2 + input->width) ==
					(input->width + 1) * input->height)
					return (1);
				else
					return (0);
			}
		}
		else
			return (0);
	}
	return (0);
}

int		check_map_char(char **maze, t_input *input)
{
	int	i;
	int	j;

	j = 0;
	while (maze[j])
	{
		i = 0;
		while (maze[j][i])
		{
			if (maze[j][i] != input->block && maze[j][i] != input->empty &&
				maze[j][i] != input->entrance && maze[j][i] != input->exit_spot)
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int		check_repeat_variable(t_input *input)
{
	if (input->block == input->empty || input->block == input->path ||
		input->block == input->entrance || input->block == input->exit_spot)
		return (1);
	if (input->empty == input->path || input->empty == input->entrance ||
		input->empty == input->exit_spot)
		return (1);
	if (input->path == input->entrance || input->path == input->exit_spot)
		return (1);
	if (input->entrance == input->exit_spot)
		return (1);
	return (0);
}

char	**create_maze_table(char *str, t_input *input)
{
	int		i;
	char	**maze;

	i = 0;
	maze = (char **)ft_memalloc(sizeof(char *) * input->height + 1);
	while (i < input->height)
	{
		maze[i] = strndup(str, input->width);
		str += input->width + 1;
		i++;
	}
	maze[i] = NULL;
	return (maze);
}

char	**check_and_gen_maze(char *readout, t_input *input)
{
	char	**maze;

	maze = create_maze_table(readout, input);
	if (!check_map_size(readout, input))
		return (NULL);
	if (!check_map_char(maze, input))
		return (NULL);
	if (input->nb_entrance != 1)
		return (NULL);
	if (input->nb_exit < 1)
		return (NULL);
	if (check_repeat_variable(input))
		return (NULL);
	return (maze);
}

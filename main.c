/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 15:37:10 by sding             #+#    #+#             */
/*   Updated: 2018/04/09 15:37:13 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

void	solve(char **maze, t_input *input)
{
	if (solve_maze(maze, input))
	{
		print_first_line(input);
		ft_print_table(maze);
		ft_putstr("RESULT IN ");
		ft_putnbr(input->steps);
		ft_putendl(" STEPS!");
	}
	else
		ft_putstrl("MAP ERROR");
	ft_free_table(maze);
	free(input);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	**maze;
	t_input	*input;

	fd = 0;
	i = 0;
	if (argc == 1)
	{
		if ((maze = read_input(0, &input, i)) == NULL)
			ft_putendl("MAP ERROR");
		else
			solve(maze, input);
	}
	while (++i < argc)
	{
		if ((fd = open(argv[i], O_RDONLY)) == -1)
			return (-1);
		if ((maze = read_input(fd, &input, i)) == NULL)
			ft_putendl("MAP ERROR");
		else
			solve(maze, input);
		close(fd);
	}
	return (0);
}

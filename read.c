/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 16:42:00 by sding             #+#    #+#             */
/*   Updated: 2018/04/10 16:42:01 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

char	*gen_maze(t_list *head, int len)
{
	char	*str;
	t_list	*tmp;

	str = ft_strnew(len);
	while (head)
	{
		ft_strcat(str, head->content);
		tmp = head;
		head = head->next;
		free(tmp->content);
		free(tmp);
	}
	return (str);
}

char	**read_input(int fd, t_input **intput, int len)
{
	char	line[BUFF_SIZE + 1];
	int		nb_read;
	t_list	*head;
	char	*maze;
	t_input	*input;

	len = 0;
	head = 0;
	while ((nb_read = read(fd, line, BUFF_SIZE)) > 0)
	{
		line[nb_read] = '\0';
		ft_lstaddtoend(&head, ft_lstnew(line, nb_read + 1));
		len += nb_read;
	}
	maze = gen_maze(head, len);
	if ((input = create_input()) == 0 || !get_input(maze, input))
	{
		free(input);
		return (0);
	}
	*intput = input;
	maze = (ft_strchr(maze, '\n'));
	return (check_and_gen_maze(maze + 1, input));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grimly.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 20:27:28 by sding             #+#    #+#             */
/*   Updated: 2018/04/09 20:27:29 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRIMLY_H
# define GRIMLY_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include "libft/libft.h"
# define BUFF_SIZE 1024

# define UP -1
# define LEFT -2
# define RIGHT -3
# define DOWN -4

typedef struct		s_input
{
	char			*map_info;
	int				height;
	int				width;
	char			block;
	char			empty;
	char			entrance;
	char			exit_spot;
	char			path;
	char			**maze;
	int				steps;
	int				pos[2];
	int				nb_entrance;
	int				nb_exit;
}					t_input;

/*
** a doubly linked list node to store a queue entry
*/

typedef struct		s_node
{
	int				x;
	int				y;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;


/*
** queue, front (rear) stores the front (last) node of linked list
*/

typedef struct		s_queue
{
	struct s_node	*front;
	struct s_node	*rear;
}					t_queue;

/*
** queue.c
*/

t_node				*create_node(int y, int x);
t_queue				*create_queue(void);
t_node				*enqueue(t_queue **queue, int y, int x);
t_node				*dequeue(t_queue **queue);

/*
** input.c
*/

t_input				*create_input(void);
void				get_character(char *str, t_input *input);
t_input				*get_input(char *str, t_input *input);
void				print_input(t_input *input);
void				get_entrance_spot(char *str, t_input *input);

/*
** check_maze.c
*/

int					check_map_size(char *str, t_input *input);
int					check_map_char(char **maze, t_input *input);
int					check_repeat_variable(t_input *input);
char				**create_maze_table(char *str, t_input *input);
char				**check_and_gen_maze(char *str, t_input *input);

/*
** read.c
*/

char				*gen_maze(t_list *head, int len);
char				**read_input(int fd, t_input **intput, int len);


/*
** print.c
*/
void				print_path(char **maze, t_node *spot, t_input *input);
void				delete_direction(char **maze, t_input *input);
void				print_first_line(t_input *input);
void				print_queue(t_queue *queue, char order);

/*
** solve.c
*/
int					is_empty(char c, t_input *input);
void				put_direction(char **maze, t_node *spot, t_queue **q,
															t_input *input);
int					is_exit(char c, t_input *input);
int					check_exit(char **maze, t_node *s, t_input *input);
int					solve_maze(char **maze, t_input *input);

void				solve(char **maze, t_input *input);

#endif

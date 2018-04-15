/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 06:04:06 by sding             #+#    #+#             */
/*   Updated: 2018/04/12 06:04:08 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

t_input	*create_input(void)
{
	t_input	*input;

	input = ft_memalloc(sizeof(t_input));
	input->block = 0;
	input->empty = 0;
	input->height = 0;
	input->width = 0;
	input->path = 0;
	input->entrance = 0;
	input->exit_spot = 0;
	input->steps = 0;
	input->nb_entrance = 0;
	input->nb_exit = 0;
	return (input);
}

void	get_character(char *str, t_input *input)
{
	input->block = *str;
	str++;
	input->empty = *str;
	str++;
	input->path = *str;
	str++;
	input->entrance = *str;
	str++;
	input->exit_spot = *str;
}

t_input	*get_input(char *str, t_input *input)
{
	int		n;

	if ((n = ft_strlen_til(str, '\n') < 5))
		return (0);
	if ((input->height = ft_atoi(str)) <= 0)
		return (0);
	while (ft_isdigit(*str))
		str++;
	if (*str != 'x')
		return (0);
	str++;
	if ((input->width = ft_atoi(str)) <= 0)
		return (0);
	if (input->width * input->height > 1000000000 ||
		input->width * input->height < 0)
		return (0);
	while (ft_isdigit(*str))
		str++;
	get_character(str, input);
	str = ft_strchr(str, '\n');
	get_entrance_spot(str + 1, input);
	return (input);
}

void	get_entrance_spot(char *str, t_input *input)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == input->entrance && input->nb_entrance < 1)
		{
			input->pos[0] = i / input->width;
			input->pos[1] = i % input->width;
			input->nb_entrance++;
		}
		else if (str[i] == input->entrance)
			input->nb_entrance++;
		else if (str[i] == input->exit_spot)
			input->nb_exit++;
		i++;
	}
}

void	print_input(t_input *input)
{
	ft_putstr("input->height: ");
	ft_putnbrl(input->height);
	ft_putstr("input->width: ");
	ft_putnbrl(input->width);
	ft_putstr("input->block: ");
	ft_putcharl(input->block);
	ft_putstr("input->empty: ");
	ft_putcharl(input->empty);
	ft_putstr("input->path: ");
	ft_putcharl(input->path);
	ft_putstr("input->entrance: ");
	ft_putcharl(input->entrance);
	ft_putstr("input->exit_spot: ");
	ft_putcharl(input->exit_spot);
	ft_putstr("input->nb_entrance: ");
	ft_putnbrl(input->nb_entrance);
	ft_putstr("input->nb_exit: ");
	ft_putnbrl(input->nb_exit);
	ft_putstr("pos[0]: ");
	ft_putnbr(input->pos[0]);
	ft_putstr(" pos[1]: ");
	ft_putnbrl(input->pos[1]);
	ft_putstrl("--------------------");
}

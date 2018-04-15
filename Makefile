# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sding <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/08 17:05:59 by sding             #+#    #+#              #
#    Updated: 2018/04/10 17:18:39 by sding            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE = make -C
NAME = grimly
LIB = libft/
FLAGS = -Wall -Wextra -Werror
CC = gcc

#When compiling. you need to add your .a lib
CFILES = $(LIB)/libft.a \
				queue.c\
				read.c\
				input.c\
				check_maze.c\
				solve.c\
				print.c\
				main.c



#These options are here in case the lib needs to be recompiled.
#LIBM, LIBC, LIBF will run rules re, clean and fclean inside the libft folder
LIBM = $(MAKE) $(LIB) re
LIBC = $(MAKE) $(LIB) clean
LIBF = $(MAKE) $(LIB) fclean
OBJECTS = $(CFILES:.c=.o)

DFLAGS = $(CFLAGS) -g $(LIBD) $(CFILES) -o
DNAME = $(NAME)_debug
DOBJS = $(CFILES:.c = .o)
# export DRAGS=01.map
all: $(NAME)

$(NAME):
	@$(LIBM)
	@$(CC) $(FLAGS) -I grimly.h -o $(NAME) $(CFILES)

clean:
	@$(LIBC)
	@/bin/rm -f $(OBJECTS)

fclean:
	@$(LIBF)
	@/bin/rm -f $(OBJECTS) $(NAME)
	rm -f $(DNAME)
	rm -rf $(DNAME).dSYM

re: fclean all



debug: $(DNAME)

$(DNAME): fclean
	@$(LIBM)
	$(CC) $(DFLAGS) $(DNAME)
	# lldb $(DNAME) $(DARGS)

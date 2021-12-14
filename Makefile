# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 16:26:57 by bepifani          #+#    #+#              #
#    Updated: 2021/12/13 15:31:11 by bepifani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = client
NAME2 = server
CC = gcc
CFLAGS = -Wall -Werror -Wextra -c

SRC_FILES_CLIENT = client.c utils.c
SRC_FILES_SERVER = server.c utils.c
SRC_FILES_UTILS = utils.c

OBJECTS_CLIENT = $(SRC_FILES_CLIENT:.c=.o)
OBJECTS_SERVER = $(SRC_FILES_SERVER:.c=.o)
OBJECTS_UTILS = $(SRC_FILES_UTILS:.c=.o)

HEADER = minitalk.h

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJECTS_CLIENT) $(HEADER)
	$(CC) $(OBJECTS_CLIENT) -o $@

$(NAME2): $(HEADER) $(OBJECTS_SERVER)
	$(CC) $(OBJECTS_SERVER) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@ 
	
clean:
	/bin/rm -f $(OBJECTS_CLIENT) $(OBJECTS_SERVER) $(OBJECTS_UTILS)

fclean: clean
	/bin/rm -f $(NAME1) $(NAME2)

re: fclean all

bonus :

.PHONY: all clean fclean re bonus
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/19 16:23:43 by fignigno          #+#    #+#              #
#    Updated: 2021/07/19 16:35:55 by fignigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = webserv
FLAGS = -g
SRC_DIR = ./src
SRCS =	$(shell ls $(SRC_DIR))
OBJ_DIR = ./obj
OBJ = $(SRCS:.cpp=.o)
OBJS = $(addprefix $(OBJ_DIR)/, $(OBJ))
INC_DIR = ./include

all: $(NAME)

$(NAME):$(OBJ_DIR) $(OBJS)
	clang++ $(FLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJS): $(OBJ_DIR)/%.o:$(SRC_DIR)/%.cpp
	clang++ $(FLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re

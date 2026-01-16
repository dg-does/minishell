# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/13 11:46:07 by digulraj          #+#    #+#              #
#    Updated: 2026/01/16 14:28:29 by digulraj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Isrc -Ilexer -Iparser
LDLIBS = -lreadline

LEX_DIR = lexer
PARSE_DIR = parser
SRC_DIR = src

SRC =	$(SRC_DIR)/main.c $(SRC_DIR)/libft.c \
		$(LEX_DIR)/lexer_utils.c $(LEX_DIR)/tokenizer.c $(LEX_DIR)/tokenizer_utils.c \
		$(PARSE_DIR)/parser.c $(PARSE_DIR)/parser_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDLIBS)
	@echo "Executable called $(NAME) created"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "Object files deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "Executable and object files deleted"

re: fclean all

.PHONY: all clean fclean re
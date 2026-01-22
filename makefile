# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/13 11:46:07 by digulraj          #+#    #+#              #
#    Updated: 2026/01/22 16:23:33 by digulraj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Isrc -Ilexer -Iparser -g
LDLIBS = -lreadline
INCLUDES = -I. -I$(LIBFT_DIR)

SRC_DIR = src
LEX_DIR = lexer
PARSE_DIR = parser
SRC_DIR = src
LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
EXP_DIR = expander

SRC =	$(SRC_DIR)/main.c \
		$(LEX_DIR)/lexer_utils.c $(LEX_DIR)/tokenizer.c $(LEX_DIR)/tokenizer_utils.c \
		$(PARSE_DIR)/parser.c $(PARSE_DIR)/parser_utils.c $(PARSE_DIR)/find_paths.c \
		$(EXP_DIR)/expander.c


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)
	
$(NAME): $(OBJ) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT_LIB) -o $(NAME) $(LDLIBS)
	@echo "Executable called $(NAME) created"

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

libft:
	make -s -C libft

clean:
	@rm -f $(OBJ)
	make clean -C libft 
	@echo "Object files deleted"

fclean: clean
	@rm -f $(NAME)
	make fclean -C libft
	@echo "Executable and object files deleted"

re: fclean all

.PHONY: all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/13 11:46:07 by digulraj          #+#    #+#              #
#    Updated: 2026/01/29 17:18:40 by digulraj         ###   ########.fr        #
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
LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
EXP_DIR = expander

SRC =	$(SRC_DIR)/main.c \
		$(LEX_DIR)/lexer_utils.c $(LEX_DIR)/tokenizer.c $(LEX_DIR)/tokenizer_utils.c \
		$(PARSE_DIR)/parser.c $(PARSE_DIR)/parser_utils.c \
		$(EXP_DIR)/expander.c $(EXP_DIR)/expander_utils.c


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT_LIB):
	@$(MAKE) -s -C $(LIBFT_DIR)
	
$(NAME): $(OBJ) $(LIBFT_LIB)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT_LIB) -o $(NAME) $(LDLIBS)
	@echo "Executable called $(NAME) created"

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@make clean -s -C $(LIBFT_DIR)
	@echo "Object files deleted"

fclean: clean
	@rm -f $(NAME)
	@make fclean -s -C $(LIBFT_DIR)
	@echo "Executable and object files deleted"

re: fclean all

.PHONY: all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/13 11:46:07 by digulraj          #+#    #+#              #
#    Updated: 2026/02/18 17:51:14 by digulraj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = minishell

SRC_DIR = src
LEX_DIR = lexer
PARSE_DIR = parser
LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
EXP_DIR = expander
BI_DIR = built_in
EXEC_DIR = exec

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(SRC_DIR) -I$(LEX_DIR) -I$(PARSE_DIR) -I$(EXP_DIR) -I$(BI_DIR) -I -g
LDLIBS = -lreadline
INCLUDES = -I. -I$(LIBFT_DIR)

SRC =	$(SRC_DIR)/main.c \
		$(LEX_DIR)/lexer_utils.c $(LEX_DIR)/tokenizer.c $(LEX_DIR)/tokenizer_utils.c \
		$(PARSE_DIR)/parser.c $(PARSE_DIR)/parser_utils.c \
		$(EXP_DIR)/expander.c $(EXP_DIR)/expander_utils.c \
		$(BI_DIR)/cd.c $(BI_DIR)/echo.c $(BI_DIR)/env.c $(BI_DIR)/exit.c $(BI_DIR)/export.c \
		$(BI_DIR)/pwd.c $(BI_DIR)/unset.c \
		$(EXEC_DIR)/execute.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT_LIB):
	@$(MAKE) -s -C $(LIBFT_DIR)
	
$(NAME): $(OBJ) $(LIBFT_LIB)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT_LIB) -o $(NAME) $(LDLIBS)
	@echo "Executable called $(NAME) created. Run with ./minishell"

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
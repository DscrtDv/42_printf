# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tcensier <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/28 08:50:07 by tcensier      #+#    #+#                  #
#    Updated: 2022/10/28 14:26:16 by tcensier      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
LIBFT := ./libft/libft.a
SRC := ft_printf.c \
	   num_utils.c \
	   handle_type.c

OBJ := $(SRC:.c=.o)
HEADERS := ft_printf.h \
		   ./libft/libft.h
CC := gcc
CFLAGS ?= -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ) libft
	@make -C ./libft
	@cp libft/libft.a $(NAME)
	@ar rcs $@ $(OBJ)
	@echo "Archive file $(NAME) successfully created and indexed."

%.o: %.c $(HEADERS)
	@$(CC) -c $(CFLAGS) -o $@ $<

clean:
	@make clean -C ./libft
	@rm -rf $(OBJ);
	@echo "OBJ files successfully deleted."

fclean: clean
	@make fclean -C ./libft
	@rm -rf $(NAME)
	@echo "$(NAME) successfully deleted".

re: fclean all
	@echo "Cleaned and rebuilt successfully."

norm:
	@norminette $(SRC) ./libft | grep -v Norme -B1 || true

.PHONY: all, libft, clean, fclean, re, norm



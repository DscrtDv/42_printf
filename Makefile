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
SRC := 
OBJ := $(SRC:.c=.o)
LIBFT_OBJ := libft/*.o

CC := gcc
CFLAGS ?= -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ) libft
	@ar rcs $@ $(OBJ) $(LIBFT_OBJ)
	@echo "Archive file $(NAME) successfully created and indexed."

%.o: %.c
	@$(CC) -c $(CFLAGS) -o $@ $<

libft:	
	@make -C libft
	@echo "Libft.a moved to root of directory."

clean:
	@rm -f $(OBJ)
	@make clean -C libft
	@echo "OBJ files successfully deleted."

fclean: clean
	@rm -f $(NAME) libft/libft.a
	@echo "$(NAME) successfully deleted."
	@echo "Libft.a successfully deleted."

re: fclean all
	@echo "Cleaned and rebuilt successfully."

norm:
	@norminette $(SRC) libft | grep -v Norme -B1 || true

.PHONY: all, libft, clean, fclean, re, norm



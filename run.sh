gcc -fsanitize=address ft_printf.h libft/libft.h ft_printf.c type_handler.c num_utils.c libft/ft_strlen.c libft/ft_strdup.c libft/ft_itoa.c libft/ft_put.c libft/ft_strlcpy.c main.c -o execute
chmod 777 execute
./execute

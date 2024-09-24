NAME	= pipex
LIB		= pipex.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I./include
RM		= rm -f
CREATE	= ar rcs
LIBFT	= libft
SRCS	= main.c utils.c execute_command.c
OBJS	= ${SRCS:.c=.o}

all: ${NAME}


${NAME}: ${LIB}
	make -C ${LIBFT}
	${CC} ${CFLAGS} ${OBJS} -L${LIBFT} -lft -o $@

${LIB}: ${OBJS}
	${CREATE} ${LIB} $^

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	make clean -C ${LIBFT}
	${RM} ${OBJS}

fclean: clean
	make fclean -C ${LIBFT}
	${RM} ${LIB}

re: fclean all

.PHONY: all clean fclean re

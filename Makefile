PIPEX		= ft_pipex.c

PIPEX_BONUS	= ft_pipex_bonus.c

SRCS		= ft_pipex_utils.c ft_split_except.c

OBJS		= ${PIPEX:.c=.o} ${SRCS:.c=.o}

OBJS_BONUS	= ${PIPEX_BONUS:.c=.o} ${SRCS:.c=.o}

CC		= cc
AR		= ar rc
RM		= rm -f
O		= -o
C		= -c

FLAGS		= -Wall -Wextra -Werror

NAME		= libftpipex.a

LIBFT		= libft.a

EXEC		= pipex

all:		$(NAME) ${EXEC}

.c.o:		${SRCS}
			${CC} ${FLAGS} ${C} $< ${O} $(<:.c=.o)

$(NAME):	${OBJS}
			make -C libft && cp libft/${LIBFT} ${NAME}
			${AR} $(NAME) ${OBJS}

${EXEC}:
			${CC} ${FLAGS} ${PIPEX} ${O} ${EXEC} -L. -lftpipex

bonus:			${OBJS_BONUS} ${NAME}
			${AR} $(NAME) ${OBJS_BONUS}
			${CC} ${FLAGS} ${PIPEX_BONUS} ${O} ${EXEC} -L. -lftpipex

clean:
			${RM} ${OBJS} ${OBJS_BONUS}
			make clean -C libft

fclean:		clean
			${RM} $(NAME) ${EXEC}
			${RM} libft/${LIBFT}

re:			fclean all

.PHONY:		all clean fclean re

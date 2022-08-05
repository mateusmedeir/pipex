PIPEX		= ft_pipex.c

PIPEX_BONUS	= ft_pipex_bonus.c

SRCS		= ft_pipex_utils.c ft_split_except.c

OBJS		= ${PIPEX:.c=.o} ${SRCS:.c=.o}

OBJS_BONUS	= ${PIPEX_BONUS.c=.o} ${SRCS:.c=.o}

CC		= cc
AR		= ar rc
RM		= rm -f
O		= -o
C		= -c

FLAGS		= -Wall -Wextra -Werror

NAME		= libftpipex.a

LIBFT		= libft.a

all:		$(NAME)

$(NAME):	${OBJS}
			@make -C libft && cp libft/${LIBFT} ${NAME}
			${AR} $(NAME) ${OBJS}
			@${CC} ${FLAGS} ${PIPEX} ${O} pipex -L. -lftpipex

.c.o:		${SRCS} ${PIPEX}
			${CC} ${FLAGS} ${C} $< ${O} $(<:.c=.o)

bonus:		${LIBFT} ${OBJS_BONUS}
			${AR} ${NAME} ${OBJS}
			@${CC} ${FLAGS} ${PIPEX_BONUS} ${O} pipex -L. -lftpipex

clean:
			${RM} ${OBJS} ${OBJS_BONUS}
			@make clean -C libft

fclean:		clean
			@${RM} ${NAME} pipex
			@${RM} libft/${LIBFT}

re:			fclean all

.PHONY:		all bonus clean fclean re

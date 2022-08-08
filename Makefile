PIPEX		= ft_main.c

PIPEX_BONUS	= ft_main_bonus.c

SRCS		= ft_pipex.c ft_pipex_utils.c ft_split_except.c

OBJS		= ${SRCS:.c=.o}

OBJS_BONUS	= ${SRCS:.c=.o}

CC			= cc
AR			= ar rc
RM			= rm -f
O			= -o
C			= -c

FLAGS		= -Wall -Wextra -Werror

NAME		= libftpipex.a

LIBFT		= libft.a

EXEC		= pipex

EXEC_BONUS	= pipex_bonus

all:			$(NAME) ${EXEC}

.c.o:			${SRCS}
				${CC} ${FLAGS} ${C} $< ${O} $(<:.c=.o)

$(NAME):		${OBJS}
				make -C libft && cp libft/${LIBFT} $(NAME)
				${AR} $(NAME) ${OBJS} ${OBJS_BONUS}

${EXEC}:
				${CC} ${FLAGS} ${PIPEX} ${O} ${EXEC} -L. -lftpipex

${EXEC_BONUS}:
				${CC} ${FLAGS} ${PIPEX_BONUS} ${O} ${EXEC_BONUS} -L. -lftpipex

bonus:			${OBJS_BONUS} $(NAME) ${EXEC_BONUS}

clean:
				${RM} ${OBJS} ${OBJS_BONUS}
				make clean -C libft

fclean:			clean
				${RM} $(NAME) ${EXEC} ${EXEC_BONUS}
				${RM} libft/${LIBFT}

re:				fclean all

.PHONY:			all bonus clean fclean re

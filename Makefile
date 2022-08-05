SRCS	= ft_pipex.c ft_pipex_utils.c ft_split_except.c

OBJS	= ${SRCS:.c=.o}

CC		= cc
AR		= ar rc
RM		= rm -f
O		= -o
C		= -c

FLAGS	= -Wall -Wextra -Werror

NAME	= libftpipex.a

LIBFT	= libft.a

PIPEX	= pipex

FTPIPEX	= -L. -lftpipex

all:		$(NAME)

$(NAME):	${LIBFT} ${OBJS}
			${AR} $(NAME) ${OBJS}
			${CC} ${FLAGS} ${SRCS} ${O} ${PIPEX} ${FTPIPEX}

${LIBFT}:	
			@make -C libft
			@cp libft/${LIBFT} . && mv ${LIBFT} libftpipex.a

.c.o:		${SRCS}
			${CC} ${FLAGS} ${C} $< ${O} $(<:.c=.o)

clean:
			${RM} ${OBJS}
			@make clean -C libft

fclean:		clean
			${RM} ${NAME} ${PIPEX}
			@${RM} libft/${LIBFT}

re:			fclean all

.PHONY:		all clean fclean re

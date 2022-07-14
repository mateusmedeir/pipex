SRCS	= ft_pipex.c ft_pipex_utils.c

OBJS	= ${SRCS:.c=.o}

CC		= cc
AR		= ar rc
RM		= rm -f
O		= -o

FLAGS	= -Wall -Wextra -Werror -c

NAME	= libftpipex.a

LIBFT	= libft.a

all:		$(NAME)

$(NAME):	${LIBFT} ${OBJS}
			${AR} $(NAME) ${OBJS}

${LIBFT}:	
			@cd libft/ && make && cd ../
			@cp libft/${LIBFT} . && mv ${LIBFT} libftpipex.a

.c.o:		${SRCS}
			${CC} ${FLAGS} $< ${O} $(<:.c=.o)

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re

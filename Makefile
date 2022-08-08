PIPEX		= ft_main.c

PIPEX_BONUS	= ft_main_bonus.c

SRCS		= ft_pipex.c ft_pipex_utils.c ft_split_except.c

OBJS		= ${SRCS:.c=.o}

CC			= cc
AR			= ar rc
RM			= rm -f
O			= -o
C			= -c

FLAGS		= -Wall -Wextra -Werror

NAME		= pipex

BONUS		= pipex_bonus

LIBFTPIPEX	= libftpipex.a

LIBFT		= libft.a

all:			$(NAME)

.c.o:			${SRCS}
				${CC} ${FLAGS} ${C} $< ${O} $(<:.c=.o)

${LIBFTPIPEX}:	${OBJS}
				make -C libft && cp libft/${LIBFT} ${LIBFTPIPEX}
				${AR} ${LIBFTPIPEX} ${OBJS}

$(NAME):		${LIBFTPIPEX}
				${CC} ${FLAGS} ${PIPEX} ${O} $(NAME) -L. -lftpipex

$(BONUS):		${LIBFTPIPEX}
				${CC} ${FLAGS} ${PIPEX_BONUS} ${O} $(BONUS) -L. -lftpipex

bonus:			$(BONUS)

clean:
				${RM} ${OBJS}
				make clean -C libft

fclean:			clean
				${RM} ${LIBFTPIPEX} $(NAME) $(BONUS)
				${RM} libft/${LIBFT}

re:				fclean all

.PHONY:			all bonus clean fclean re

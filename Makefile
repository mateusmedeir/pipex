NAME		= pipex

BONUS		= pipex_bonus

SRCS_M		= ft_main.c

SRCS_B		= ft_main_bonus.c

SRCS_F		= ft_pipex.c 	    \
			  ft_pipex_utils.c  \
			  ft_split_except.c

OBJS_M		= $(SRCS_M:.c=.o)

OBJS_B		= $(SRCS_B:.c=.o)

OBJS_F		= $(SRCS_F:.c=.o)

LIBFT		= libft/libft.a

CC			= cc
AR			= ar rc
RM			= rm
FLAGS		= -Wall -Wextra -Werror

all:			$(NAME)

$(NAME):		$(LIBFT) $(OBJS_M) $(OBJS_F)
				$(CC) $(FLAGS) $(OBJS_M) $(OBJS_F) -o $(NAME) -Llibft -lft

.c.o:
				$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(LIBFT):
				make -C libft

bonus:			$(BONUS)

$(BONUS):		$(LIBFT) $(OBJS_B) $(OBJS_F)
				$(CC) $(FLAGS) $(OBJS_B) $(OBJS_F) -o $(BONUS) -Llibft -lft

clean:
				$(RM) -f $(OBJS_M) $(OBJS_B) $(OBJS_F)
				make clean -C libft

fclean:			clean
				$(RM) -f $(NAME) $(BONUS)
				$(RM) -f $(LIBFT)

re:				fclean all

.PHONY:			all bonus clean fclean re

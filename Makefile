SRC = pipex.c pipex_utils.c pipex_utils_2.c ft_split.c ft_strncmp.c ft_putchar_fd.c ft_putstr_fd.c ft_substr.c ft_strjoin.c ft_strlen.c  ft_strlcat.c ft_strrchr.c

BONUS_SRC = pipex_bonus.c pipex_utils.c pipex_utils_2.c ft_split.c ft_strncmp.c ft_putchar_fd.c ft_putstr_fd.c ft_substr.c ft_strjoin.c ft_strlen.c  ft_strlcat.c ft_strrchr.c

OBJS = $(SRC:.c=.o)

BONUS_OBJS = $(BONUS_SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -static-libsan -g

#CFLAGS = -Wall -Wextra -Werror

NAME = pipex

BONUS_NAME = pipex_bonus

$(NAME) :
		$(CC) $(CFLAGS) $(SRC) -o $(NAME)

$(BONUS_NAME) :
		$(CC) $(CFLAGS) $(BONUS_SRC) -o $(BONUS_NAME)

all : $(NAME)

bonus : $(BONUS_NAME)

clean :
		@rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
		 rm -f $(NAME) $(BONUS_NAME)

re : fclean all	

.PHONY: all clean fclean re

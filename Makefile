SRC = pipex.c pipex_utils.c pipex_utils_2.c ft_split.c ft_strncmp.c ft_putchar_fd.c ft_putstr_fd.c ft_substr.c ft_strjoin.c ft_strlen.c  ft_strlcat.c ft_strrchr.c

BONUS_SRC = pipex_bonus.c pipex_utils_bonus.c pipex_utils_2_bonus.c ft_split.c ft_strncmp.c ft_putchar_fd.c ft_putstr_fd.c ft_substr.c ft_strjoin.c ft_strlen.c  ft_strlcat.c ft_strrchr.c

OBJS = $(SRC:.c=.o)

BONUS_OBJS = $(BONUS_SRC:.c=.o)

CC = cc

#CFLAGS = -Wall -Wextra -Werror -fsanitize=address -static-libsan -g

CFLAGS = -Wall -Wextra -Werror

NAME = pipex

$(NAME) :
		$(CC) $(CFLAGS) $(SRC) -o $(NAME)

all : $(NAME)

bonus : 
		$(CC) $(CFLAGS) $(BONUS_SRC) -o $(NAME)

clean :
		@rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
		 rm -f $(NAME)

re : fclean all	

.PHONY: all clean fclean re

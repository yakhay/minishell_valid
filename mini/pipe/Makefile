SRC = exect_cmd.c  run_cmd.c exect_utilis.c\
 	  ../parsing/mn.c ../parsing/ft_split1.c ../parsing/mn_utils.c ../parsing/mn_utils2.c ../parsing/ft_strjoin_prs.c ../parsing/exp.c ../parsing/exp1.c\
	  ../parsing/mn_utils3.c  ../parsing/add_space.c ../parsing/herdoc.c ../parsing/skip_quotes.c ../parsing/ft_initialize.c\
	  ../parsing/split_cmd.c ../parsing/error.c ../builtins/builins_utilis.c  ../builtins/ft_strjoin_and_free.c  main_utilis.c\
 	  ../builtins/builtins.c ../builtins/cmd_cd.c ../builtins/cmd_echo.c ../builtins/cmd_pwd.c ../builtins/env.c ../builtins/exit.c ../builtins/export.c ../builtins/fill_env.c ../builtins/unset.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3
NAME  = minishell
FLAGS = -lreadline -L /Users/yakhay/Desktop/readline -I/Users/yakhay/Desktop/readline -lcurses
all : $(NAME)
$(NAME) : $(OBJ)
	cc $(CFLAGS) $(FLAGS)  $(OBJ) ../libft/libft.a  -o $(NAME)

clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all


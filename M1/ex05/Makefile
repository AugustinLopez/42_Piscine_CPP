NAME=Karen
COMPILER=clang++
FLAGS=-g3 -Werror -Wall -Wextra -MMD -MP -std=c++98
EXT=cpp

VPATH=
PATH_OBJ=.object/
PATH_HDR=.

SRC=main Karen

CC_O=$(COMPILER) $(FLAGS) -c -I$(PATH_HDR)
CC_C=$(COMPILER) $(FLAGS) $(OBJ)
OBJ=$(SRC:%=$(PATH_OBJ)%.o)
DEP=$(OBJ:%.o=%.d)

# ==== RULES ==== #

all: $(NAME)

$(NAME) : $(OBJ)
	-@printf " ===> \e[32mCreated executable\e[0m: $(NAME)\n"
	@$(CC_C) -o $(NAME)

$(PATH_OBJ)%.o:%.cpp | $(PATH_OBJ)
	-@printf " > \e[33m$*.o\e[0m\n"
	@$(CC_O) $< -o $@

$(PATH_OBJ):
	-@printf " ===> \e[32mCreated directory\e[0m: $(PATH_OBJ)\n"
	@mkdir -p $@

clean:
	-@printf " ===> \e[31mDeleted directory\e[0m: $(PATH_OBJ)\n"
	@rm -rf $(PATH_OBJ)

fclean: clean
	-@printf " ===> \e[31mDeleted executable\e[0m: $(NAME)\n"
	@rm -f $(NAME)

re: fclean $(PATH_OBJ) all

.PHONY: all clean fclean re

-include $(DEP)

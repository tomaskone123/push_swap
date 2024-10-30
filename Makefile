NAME 		= push_swap
CFLAGS 		= -Wall -Werror -Wextra -g
CC 			= cc
RM			= rm
SRC_DIR 	= src
INC			= -I ./inc/
LIB_INC 	= -I ./libft
BIN_DIR 	= bin
LIB_DIR 	= libft
LIB_CUT		= $(shell echo $(LIB_DIR) | cut -c 4-)
################################################################################
## COLORS
GREEN		= \033[0;92m
YELLOW		= \033[0;93m
BLUE		= \033[0;94m
RED			= \033[0;91m
END_COLOR	= \033[0;39m
################################################################################
## SOURCES
SRC_FILES	=	push \
	reverse \
	rotate \
	sort_three \
	sort \
	swap \
	a_to_b \
	b_to_a \
	errors \
	main \
	stack_init \
	utils
OBJ			= $(addprefix $(BIN_DIR)/, $(addsuffix .o, $(SRC_FILES)))
SRC			= $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC_FILES)))
################################################################################
## RULES
all: $(NAME)

$(NAME): $(OBJ)
	+@make -C libft --no-print-directory
	+@$(CC) -o $(NAME) $(OBJ) -L $(LIB_DIR) -l $(LIB_CUT)
	+@echo "$(GREEN)$(NAME) compiled.$(END_COLOR)"

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c Makefile libft/*.c | $(BIN_DIR)
	+@$(CC) -c $(CFLAGS) $(INC) $(LIB_INC) $< -o $@
	+@echo "$(BLUE)Compiling... $(notdir $<)$(END_COLOR)"

$(BIN_DIR):
	+@mkdir $(BIN_DIR)
	+@echo "$(YELLOW)Created $(BIN_DIR)/ directory at $(NAME)/$(END_COLOR)"

clean:
	+@rm -rf $(BIN_DIR)
	+@echo "$(GREEN)$(NAME) object files cleaned.$(END_COLOR)"
	+@make clean -C libft --no-print-directory

fclean: clean
	+@rm -f $(NAME)
	+@echo "$(YELLOW)$(NAME) executable file cleaned.$(END_COLOR)"
	+@rm -f libft/libft.a
	+@echo "$(YELLOW)$(LIB_DIR).a file cleaned.$(END_COLOR)"

re: fclean all
	+@echo "$(RED)Cleaned all and rebuilt $(NAME) and $(LIB_DIR)$(END_COLOR)"

################################################################################
## TESTS

test2:		$(NAME)
	+$(eval ARG = $(shell shuf -i 0-5000 -n 2 | awk '{print $$1 - 1000}'))
	+./push_swap $(ARG) | ./checker_linux $(ARG)
	+@echo -n "$(GREEN)^ checker output\n$(END_COLOR)"
	+@echo -n "$(YELLOW)Instructions: $(END_COLOR)"
	+@./push_swap $(ARG) | wc -l

test3:		$(NAME)
	+$(eval ARG = $(shell shuf -i 0-5000 -n 3 | awk '{print $$1 - 1000}'))
	+./push_swap $(ARG) | ./checker_linux $(ARG)
	+@echo -n "$(GREEN)^ checker output\n$(END_COLOR)"
	+@echo -n "$(YELLOW)Instructions: $(END_COLOR)"
	+@./push_swap $(ARG) | wc -l

test100:		$(NAME)
	+$(eval ARG = $(shell shuf -i 0-5000 -n 100 | awk '{print $$1 - 1000}'))
	+./push_swap $(ARG) | ./checker_linux $(ARG)
	+@echo -n "$(GREEN)^ checker output\n$(END_COLOR)"
	+@echo -n "$(YELLOW)Instructions: $(END_COLOR)"
	+@./push_swap $(ARG) | wc -l


test500:		$(NAME)
	+$(eval ARG = $(shell shuf -i 0-5000 -n 500 | awk '{print $$1 - 1000}'))
	+./push_swap $(ARG) | ./checker_linux $(ARG)
	+@echo -n "$(GREEN)^ checker output\n$(END_COLOR)"
	+@echo -n "$(YELLOW)Instructions: $(END_COLOR)"
	+@./push_swap $(ARG) | wc -l

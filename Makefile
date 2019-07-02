# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlandema <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 12:04:00 by tlandema          #+#    #+#              #
#    Updated: 2019/07/02 10:04:24 by tlandema         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc

CFLAGS = -Wall -Wextra -Werror -I./includes -I./libft/includes

LIB = -lft

LIBFT = libft

LIB_PATH = -L./$(LIBFT)

INC = includes

OBJS_PATH = obj

#/********************LEM_IN****************\

LEM_IN_NAME = lem-in

LEM_IN_PATH = srcs

LEM_IN = main.c \
		 free_functions.c \
		 error_printer.c \
		 tree_balance2.c \
		 tree_balance.c \
		 link_tree.c \
		 parsing.c \
		 tree_search.c \
		 stock.c \
		 tree.c \

LEM_IN_OBJS = $(LEM_IN:.c=.o)

D_LEM_IN_OBJS = $(addprefix $(OBJS_PATH)/, $(LEM_IN_OBJS))

#\**********************************************/

D_LIB = libft/libft.a

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

define run_and_test_r
printf "%b" "$(COM_COLOR)$(COM_STRING) $(OBJ_COLOR)$(@F)$(NO_COLOR)\r"; \
	$(1) 2> $@.log; \
	RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
	printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"   ; \
	elif [ -s $@.log ]; then \
	printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"   ; \
	else  \
	printf "%-60b%b" "$(COM_COLOR)$(BACK_COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"   ; \
	fi; \
	rm -f $@.log 2> /dev/null; \
	exit $$RESULT
endef

define run_and_test
printf "%b" "$(COM_COLOR)$(COM_STRING) $(OBJ_COLOR)$(@F)$(NO_COLOR)\r"; \
	$(1) 2> $@.log; \
	RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
	printf "%-60b%b" "$(COM_COLOR)$(BACK_COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"   ; \
	elif [ -s $@.log ]; then \
	printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"   ; \
	else  \
	printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"   ; \
	fi; \
	cat $@.log; \
	rm -f $@.log; \
	exit $$RESULT
endef

OK_STRING    = "[OK]"
ERROR_STRING = "[ERROR]"
WARN_STRING  = "[WARNING]"
COM_STRING   = "Compiling"

all: $(LEM_IN_NAME)

$(LEM_IN_NAME): $(INC) $(D_LEM_IN_OBJS) $(D_LIB)
	@$(call run_and_test, $(CC) $(CFLAGS) -o $(LEM_IN_NAME) $(D_LEM_IN_OBJS) $(LIB_PATH) $(LIB))

$(OBJS_PATH)/%.o: $(LEM_IN_PATH)/%.c
	@$(call run_and_test, $(CC) $(CFLAGS) -o $@ -c $< -I$(LIB_PATH))

$(D_LIB) :
	@make -C libft

norme:
	@$(call run_and_test_r, norminette | grep -v 'Warning: Not a valid file' | grep -B 1 -e 'Error' -e 'Warning')

clean:
	@$(call run_and_test, rm -f $(D_LEM_IN_OBJS) && make clean -C libft)

fclean: clean
	@$(call run_and_test, rm -f $(LEM_IN_NAME) && rm -f libft/libft.a)

re: fclean all

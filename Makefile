# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brichard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 12:04:00 by brichard          #+#    #+#              #
#    Updated: 2019/09/18 16:20:45 by brichard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
#                                 BUILD TARGETS                                #
#------------------------------------------------------------------------------#

NAME = lem-in

SRCS += $(CORE)
SRCS += $(BINARY_TREE)
SRCS += $(PARSER)
SRCS += $(ALGO)
SRCS += $(MEMORY)

OBJS = $(patsubst %.c, $(OBJS_PATH)%.o, $(SRCS))

LIBS += $(addprefix $(LIB_PATH), $(LIB_FILES))

#------------------------------------------------------------------------------#
#                                   LIB_FILES                                  #
#------------------------------------------------------------------------------#

LIB_FILES += libft.a

#------------------------------------------------------------------------------#
#                                   INC_FILES                                  #
#------------------------------------------------------------------------------#

INC_FILES += lem_in.h
INC_FILES += define.h

#------------------------------------------------------------------------------#
#                                   SRCS_FILES                                 #
#------------------------------------------------------------------------------#

CORE += main.c

BINARY_TREE += room_tree.c
BINARY_TREE += link_tree.c
BINARY_TREE += balance_room_tree.c
BINARY_TREE += balance_room_tree_2.c
BINARY_TREE += tree_search.c
BINARY_TREE += print_tree.c
BINARY_TREE += ft_free_room_tree.c
BINARY_TREE += ft_free_link_tree.c

PARSER += parsing.c
PARSER += get_ants.c
PARSER += get_rooms.c
PARSER += get_links.c
PARSER += com_parser.c

MEMORY += del_splited_line.c

ALGO += 

#------------------------------------------------------------------------------#
#                                  DIRECTORIES                                 #
#------------------------------------------------------------------------------#

INC_DIR += includes/

OBJS_DIR += obj/

SRCS_DIR += srcs/

LIB_DIR += $(basename $(LIB_FILES))

CORE_DIR += core/

PARSING_DIR += parsing/
PARSING_DIR += parsing/com_parser/
PARSING_DIR += parsing/get_functions/

BINARY_TREE_DIR += binary_tree/
BINARY_TREE_DIR += binary_tree/balance/
BINARY_TREE_DIR += binary_tree/create_tree/
BINARY_TREE_DIR += binary_tree/tree_tools/
BINARY_TREE_DIR += binary_tree/delete_tree/

MEMORY_FUNCTIONS_DIR += memory_functions/

#------------------------------------------------------------------------------#
#                                     PATHS                                    #
#------------------------------------------------------------------------------#

INC_PATH += $(INC_DIR)
INC_PATH += $(addsuffix $(INC_DIR), $(LIB_DIR)/)

OBJS_PATH = $(OBJS_DIR)

_SRCS_PATH += $(CORE_DIR)
_SRCS_PATH += $(PARSING_DIR)
_SRCS_PATH += $(BINARY_TREE_DIR)
_SRCS_PATH += $(MEMORY_FUNCTIONS_DIR)

SRCS_PATH += $(SRCS_DIR)
SRCS_PATH += $(addprefix $(SRCS_DIR), $(_SRCS_PATH))

LIB_PATH += $(LIB_DIR)

#------------------------------------------------------------------------------#
#                                     VPATH                                    #
#------------------------------------------------------------------------------#

vpath %.c $(SRCS_PATH)
vpath %.h $(INC_PATH)

#------------------------------------------------------------------------------#
#                                  COMPILATION                                 #
#------------------------------------------------------------------------------#

CC = gcc

DEBUG += $(CFLAGS)
DEBUG += -fsanitize=address
DEBUG += -g3

IFLAGS += $(addprefix -I, $(INC_PATH))

LDFLAGS = $(addprefix -L , $(LIB_PATH))

LDLIBS = $(subst lib, -l, $(LIB_PATH))

CFLAGS += -Werror
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += $(IFLAGS)

#------------------------------------------------------------------------------#
#                                   COMMANDS                                   #
#------------------------------------------------------------------------------#

CLEAR = clear

MKDIR = mkdir -p

RM = rm -rf

#------------------------------------------------------------------------------#
#                                    CLEAN                                     #
#------------------------------------------------------------------------------#

CLEAN_LIB += $(addprefix make clean -C , $(LIB_PATH))

FCLEAN_LIB += $(addprefix make fclean -C , $(LIB_PATH))

#------------------------------------------------------------------------------#
#                                    OUTPUT                                    #
#------------------------------------------------------------------------------#

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

define run_and_test
printf "%b" "$(COM_COLOR)$(COM_STRING) $(OBJ_COLOR)$(@F)$(NO_COLOR)\r"; \
	$(1) 2> $@.log; \
	RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
		printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"   ; \
	elif [ -s $@.log ]; then \
		printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"   ; \
	else  \
		printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"   ; \
	fi; \
	cat $@.log; \
	rm -f $@.log 2> /dev/null; \
	exit $$RESULT
endef

OK_STRING    = "[OK]"
ERROR_STRING = "[ERROR]"
WARN_STRING  = "[WARNING]"
COM_STRING   = "Compiling"

#------------------------------------------------------------------------------#
#                                   COMMANDS                                   #
#------------------------------------------------------------------------------#

.PHONY: all clean fclean re
.SILENT:

all: $(CLEAR) $(NAME)

$(NAME): $(LIBS) $(OBJS_PATH) $(OBJS)
	$(call run_and_test, $(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -o $@)

$(OBJS): $(OBJS_PATH)%.o : %.c $(INCS) Makefile
	$(call run_and_test, $(CC) $(CFLAGS) -c $< -o $@)

$(OBJS_PATH):
	$(MKDIR) $@

$(LIBS):
	echo "$(COM_COLOR)Compiling $(OBJ_COLOR)Libraries$(NO_COLOR)"
	make -C $(LIB_PATH)

$(CLEAR):
	$@

norme:
	norminette $(SRCS_PATH) $(INC_PATH) | grep -v 'Warning: Not a valid file' | grep -B 1 -e 'Error' -e 'Warning'

lc:
	$(call run_and_test, $(RM) $(OBJS_PATH) && $(CLEAN_LIB))

lfc:
	$(call run_and_test, $(RM) $(OBJS_PATH) && $(RM) $(NAME) && $(FCLEAN_LIB))

clean: $(CLEAR)
	$(call run_and_test, $(RM) $(OBJS_PATH))

fclean: $(CLEAR) clean
	$(call run_and_test, $(RM) $(NAME))

re: fclean all

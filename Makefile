# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brichard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 12:04:00 by brichard          #+#    #+#              #
#    Updated: 2019/09/17 16:18:32 by brichard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
#                                 BUILD TARGETS                                #
#------------------------------------------------------------------------------#

NAME = lem-in

SRCS += $(CORE)
SRCS += $(PARSER)

OBJS = $(patsubst %.c, $(OBJS_PATH)%.o, $(SRCS_FILES))

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

PARSER += parsing.c
PARSER += room_tree.c
PARSER += link_tree.c
PARSER += balance_room_tree.c
PARSER += balance_room_tree_2.c
PARSER += tree_search.c

#------------------------------------------------------------------------------#
#                                  DIRECTORIES                                 #
#------------------------------------------------------------------------------#

INC_DIR += includes/

OBJS_DIR += obj/

SRCS_DIR += srcs/

LIB_DIR += $(basename $(LIB_FILES))/

CORE_DIR += core/

PARSING_DIR += parsing/

#------------------------------------------------------------------------------#
#                                     PATHS                                    #
#------------------------------------------------------------------------------#

INC_PATH += $(INC_DIR)
INC_PATH += $(addsuffix $(INC_DIR), $(LIB_DIR))

OBJS_PATH = $(OBJS_DIR)

_SRCS_PATH += $(CORE_DIR)
_SRCS_PATH += $(PARSING_DIR)

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

LDFLAGS = $(addprefix -L, $(LIB_PATH))

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

CLEAN_LIB += $(addprefix && make clean -C , $(LIB_PATH))

FCLEAN_LIB += $(addprefix && make fclean -C , $(LIB_PATH))

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
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) $(OBJS) -o $@

$(OBJS): $(OBJS_PATH)%.o : %.c $(INCS) Makefile | $(OBJS_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LIB_INC) -o $@ -c $<

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
	$(RM) $(D_OBJS) && $(RM) $(OBJS_PATH) $(CLEAN_LIB)

lfc:
	$(RM) $(D_OBJS) && $(RM) $(OBJS_PATH) && $(RM) $(NAME) $(FCLEAN_LIB)

clean:
	$(RM) $(OBJS_PATH)

fclean: clean
	$(RM) $(NAME)

re: fclean all

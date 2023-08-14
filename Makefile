NAME := tmp

CC := cc
CFLAGS := -Wall -Wextra -Werror
DEPSFLAGS := -MMD -MP

SRC := $(wildcard src/*.c)
OBJ := $(SRC:src/%.c=obj/%.o)
DEP := $(SRC:src/%.c=obj/%.d)

OBJ_DIR := $(sort $(dir $(OBJ)))
OBJ_DIR := $(addsuffix .keep, $(OBJ_DIR))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

obj/%.o: src/%.c $(OBJ_DIR)
	$(CC) $(CFLAGS) $(DEPSFLAGS) -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $(@D)
	touch $@

-include $(DEP)

clean:
	rm -f $(OBJ) $(DEP)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

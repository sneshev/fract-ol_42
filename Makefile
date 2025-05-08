NAME = FRACTOL
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

MINILIBX = https://github.com/42paris/minilibx-linux.git
MLIBX_PATH = minilibx

all: mlibft #$(NAME)

mlibft:
	@if [ ! -d "$(MLIBX_PATH)" ]; then \
		git clone $(MINILIBX) $(MLIBX_PATH); \
	fi
	@cd $(MLIBX_PATH) && ./configure

$(MLIBX_PATH)/build/libmlx42.a:
	@[ -d "$(MLIBX_PATH)" ] || git clone $(MINILIBX) $(MLIBX_PATH)


$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

SRCS = $(wildcard src/*.c) #$(wildcard utils/*.c)
OBJS_DIR = obj
OBJS = $(SRCS:src/%.c=$(OBJS_DIR)/%.o)
# OBJS := $(OBJS:utils/%.c=$(OBJS_DIR)/%.o)

# $(OBJS_DIR)/%.o: utils/%.c
# 	@mkdir -p $(OBJS_DIR)
# 	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(OBJS_DIR)/%.o: src/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@


fclean:
	rm -rf $(MLIBX_PATH)
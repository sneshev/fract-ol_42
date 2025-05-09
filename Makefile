NAME = FRACTOL
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

MINILIBX = https://github.com/42paris/minilibx-linux.git
MLIBX_PATH = minilibx
LIBFT = git@github.com:sneshev/libft_42.git
LIBFT_PATH = libft
all: libft #mlibx $(NAME)

mlibx: 
	@[ -d "$(MLIBX_PATH)" ] || git clone $(MINILIBX) $(MLIBX_PATH);
	@cd $(MLIBX_PATH) && ./configure

libft:
	@[ -d "$(LIBFT_PATH)" ] || git clone $(LIBFT) $(LIBFT_PATH);
	@cd $(LIBFT_PATH) && make 

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
	rm -rf $(MLIBX_PATH) $(LIBFT_PATH)
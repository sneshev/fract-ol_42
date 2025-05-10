NAME = fractol
CC = gcc
CFLAGS = -g # -Wall -Wextra -Werror 

MINILIBX = https://github.com/42paris/minilibx-linux.git
MLIBX_PATH = minilibx
LIBFT = git@github.com:sneshev/libft_42.git
LIBFT_PATH = libft
all:  libft $(NAME) #mlibx 

mlibx: 
	@[ -d "$(MLIBX_PATH)" ] || git clone $(MINILIBX) $(MLIBX_PATH);
	@cd $(MLIBX_PATH) && ./configure

libft:
	@[ -d "$(LIBFT_PATH)" ] || git clone $(LIBFT) $(LIBFT_PATH);
	@cd $(LIBFT_PATH) && make 

SRCS = $(wildcard src/*.c)
OBJS_DIR = obj
OBJS = $(SRCS:src/%.c=$(OBJS_DIR)/%.o)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: src/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

# Include libft in the linking process
LIBS = -L$(LIBFT_PATH) -lft

# Ensure libft is built before linking
$(NAME): $(OBJS) libft
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

fclean:
	rm -rf $(MLIBX_PATH) $(LIBFT_PATH) $(OBJS_DIR) $(NAME)

re: fclean all
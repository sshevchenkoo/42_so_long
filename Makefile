NAME = so_long.a
PRINTFNAME = libftprintf.a
MINILIBX = minilibx-linux/libmlx_Linux.a
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
PRINTFDIR = ./libft_upgrade
MINILIBXDIR = ./minilibx-linux

SRCS = so_long.c src/check_map.c src/check_form_map.c \
		src/check_path.c src/play.c \
		src/play_utils.c src/player.c src/free_and_quit.c
OBJS = $(SRCS:.c=.o)

all: $(NAME) so_long

makelibft:
	@make -C $(MINILIBXDIR)
	@make -C $(PRINTFDIR)
	@cp $(PRINTFDIR)/$(PRINTFNAME) .
	@mv $(PRINTFNAME) $(NAME)

$(NAME): makelibft $(OBJS)
	@ar -r $(NAME) $(OBJS)

so_long: $(NAME)
	$(CC) $(CFLAGS) so_long.c $(NAME) $(MINILIBX) -Imlx_linux -lXext -lX11 -lm -o so_long

clean:
	@rm -f $(OBJS)
	@cd $(PRINTFDIR) && make clean
	@cd $(MINILIBXDIR) && make clean
	
fclean: clean
	@rm -f $(NAME) so_long
	@cd $(PRINTFDIR) && make fclean
	
re: fclean all

.PHONY: all re fclean clean

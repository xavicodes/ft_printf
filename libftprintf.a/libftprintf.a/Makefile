NAME = libftprintf.a


SRCS = ft_printf.c ft_addprintf.c 

OBJS = $(SRCS:.c=.o)


CFLAGS = -wall -Werror -Wextra

AR = ar rc



clean:
	@$(MAKE) clean -C $(LIBFTDIR)
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(LIBFT)
	$(RM) $(NAME)

re:	fclean all



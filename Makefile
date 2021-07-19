RED			=	\033[0;31m

YELLOW		=	\033[0;33m

GREEN		=	\033[0;32m

NC			=	\033[0m

CC			=	clang++

NAME		=	webserv

CFLAGS		=	#-Wall -Wextra -Werror

SRCDIR		=	srcs

BUILDDIR	=	objs

HDRS		=	hdrs/ParseConfig.hpp \
				hdrs/ServerNode.hpp \
				hdrs/LocationNode.hpp

SRCS		=	srcs/ParseConfig.cpp \
				srcs/ServerNode.cpp \
				srcs/LocationNode.cpp \
				srcs/main.cpp

OBJS		=	$(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SRCS:.cpp=.o))

RM			=	rm -f

all:		$(NAME)

$(NAME):		$(OBJS)
			@echo "$(YELLOW)Create webserv from objects...$(NC)"
			@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
			@echo "$(GREEN)DONE!$(NC)"

$(OBJS):	|$(BUILDDIR)

$(BUILDDIR):
			@echo "$(YELLOW)Create objects...$(NC)"
			@mkdir $(BUILDDIR)

$(BUILDDIR)/%.o:	$(SRCDIR)/%.cpp $(HDRS)
			$(CC) $(CFLAGS) -I hdrs -c $< -o $@

clean:
			@$(RM) -r $(BUILDDIR)
			@echo "$(RED)Delete objects...$(NC)"

fclean:		clean
			@$(RM) $(NAME)
			@echo "$(RED)Delete webserv...$(NC)"
			@echo "$(GREEN)DONE!$(NC)"

re:			fclean all

.PHONY:		all clean fclean re

NAME=libparser.a
AR=ar rcs
DEBUG=-g -O0
CFLAGS=-Wall -Werror -Wextra $(DEBUG)
SRC=emptyline.c \
	findplayer.c \
	floodfill.c \
	gnl.c \
	headersize.c \
	mapenclosure.c \
	newcfg.c \
	padmap.c \
	param2flag.c \
	parampresence.c \
	paramvalues.c \
	parsefile.c \
	removeheader.c \
	substr.c \
	validatemap.c \
	loadmap.c

OBJDIR=./build
OBJ=$(addprefix $(OBJDIR)/,$(SRC:.c=.o))

all: top $(NAME) bottom

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $<
	@printf "\t'$@' compiled ($(CC), $(CFLAGS), $<)\n"

$(NAME): $(OBJ)
	@printf "\tcreating '$@'\n"
	@$(AR) $@ $^
	@printf "\t'$@' created\n"

clean:
	@rm -rf $(OBJDIR)
	@printf " > Removed '$(OBJDIR)'\n"

fclean: clean
	@rm -f $(NAME)
	@printf " > Removed '$(NAME)'\n"

re: fclean all

default: $(NAME)

top:
	@printf "ottomata presents:\n"

bottom:
	@printf "$(NAME) finished.\n"
.PHONY: all clean fclean re top bottom

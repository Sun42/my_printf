ifeq (${OSTYPE}, FreeBSD)
	CC	=	gcc 
	NAME	=	libmy_printf_i386-FreeBSD.a
else 
	CC	=	/usr/sfw/bin/gcc 
	NAME	=	libmy_printf_sun4u-SunOS.a
endif 

##CC_FREEBSD =  gcc
##CC_solaris = /usr/bin/sfw/gcc
##CC = $(CC_${OSTYPE}) 
SRC = 	my_printf.c \
	parser.c \
	fill_spec.c \
	fill_flag1.c \
	fill_flag2.c \
	fill_largeur.c \
	fill_precision.c \
	calcul.c \
	calcul_short.c \
	calcul_long.c \
	converter.c \
	converter_short.c \
	converter_long.c \
	display_converted.c \
	display_unsigned_num.c \
	display_signed_num.c \
	utils_display1.c \
	utils_display2.c \
	print_strings.c \
	print_special_string.c \
	print_decimal.c \
	print_short_decimal.c \
	print_short_undecimal.c \
	print_long_decimal.c \
	print_long_undecimal.c \
	print_undecimal.c \
	sharp.c \
	my_putstr.c \
	my_strlen.c \
	my_putchar.c \
	my_strcat.c \
	my_strncat.c \
	my_strdup.c \
	my_strcpy.c \
	my_getnbr.c
OBJ = $(SRC:.c=.o)
CFLAGS += -W -Wall -pedantic -ansi -I.
RM = rm -f
INCLUDES = -I.

$(NAME): all

all:
	$(CC) -c $(SRC) $(INCLUDES)
	ar r $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

CC = g++
FLAG = -Wall -Wextra -Werror -std=c++98
NAME = btc
OBJS = $(SRCS:.cpp=.o)
SRCS = main.cpp BitcoinExchange.cpp

%.o: %.cpp
	$(CC) $(FLAG) -o $@ -c $<

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
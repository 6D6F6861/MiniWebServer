NAME = miniServer

SRCS = ./server/server.cpp ./request/request.cpp ./response/response.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(FLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	c++ -c $< -o $@

clean:
	rm -f $(OBJS) $(NAME)
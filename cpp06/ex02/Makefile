NAME = Type
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Functions.cpp Classes.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = Functions.hpp Base.hpp A.hpp B.hpp C.hpp

all: $(NAME)

$(NAME): $(OBJS) Makefile
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

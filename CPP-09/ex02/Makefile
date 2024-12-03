SRC =				main.cpp \
					PmergeMe.cpp

HEADERS =			PmergeMe.hpp \
					PmergeMe.tpp


C++FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -g3

NAME = RPN

OBJ = $(SRC:.cpp=.o)

GREEN = \033[0;32m
NC = \033[0m
YELLOW = \e[0;93m
RED = \033[0;31m


$(NAME): $(OBJ)
	c++ $(C++FLAGS) $(OBJ) -o $(NAME)
	@echo "	 			$(RED)+------------------------+\n \
					|  $(YELLOW)       RPN$(GREEN)[OK]$(RED)        |\n \
					+------------------------+$(NC)"

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

%.o: %.cpp $(HEADERS)
	c++ $(CXXFLAGS) -c $< -o $@

re: fclean
	make all

.PHONY: all clean fclean re

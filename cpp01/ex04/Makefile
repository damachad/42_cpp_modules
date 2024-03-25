# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 10:46:37 by damachad          #+#    #+#              #
#    Updated: 2024/03/25 10:29:03 by damachad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ COMMANDS /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ #
CXX = c++
RM = rm -rf

# /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ FLAGS _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ #

CXXFLAGS 	= -Wall -Werror -Wextra -std=c++98

# /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ FILES _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ #

NAME 		= sed
FILES 		= main
SRC 		= $(addsuffix .cpp, $(FILES))
OBJ 		= $(addsuffix .o, $(FILES))

# /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/ ARGUMENTS \_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ #

FILENAME = test1
S1 = everyone
S2 = anyone
ARGS = $(FILENAME) $(S1) $(S2)

# /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ RULES _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ #

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME) $(FILENAME) $(FILENAME).replace

re: fclean all

test: $(NAME) $(FILENAME)
	@./$(NAME) $(FILENAME) $(S1) $(S2)
	@cat $(FILENAME)
	@echo ""
	@cat $(FILENAME).replace

$(FILENAME):
	@echo "Hello everyone, this is a test. everyone \neveryone here is good" >> $(FILENAME)
	@echo "Hello everyone, this is a test. everyone \neveryone here is good" >> $(FILENAME)
	@echo "Hello everyone, this is a test. everyone \neveryone here is good" >> $(FILENAME)

.PHONY: all clean fclean re test
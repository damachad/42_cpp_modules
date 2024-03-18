# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 10:46:37 by damachad          #+#    #+#              #
#    Updated: 2024/03/18 14:08:28 by damachad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ COMMANDS /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ #
CXX = c++
RM = rm -rf

# /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ FLAGS _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ #

CXXFLAGS 	= -Wall -Werror -Wextra -std=c++98

# /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ FILES _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ #

NAME 		= phonebook
FILES 		= main PhoneBook Contact
SRC 		= $(addsuffix .cpp, $(FILES))
OBJ 		= $(addsuffix .o, $(FILES))

# /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ RULES _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ #

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
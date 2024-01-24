# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabel <aabel@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/21 11:26:48 by babels            #+#    #+#              #
#    Updated: 2024/01/24 14:48:24 by aabel            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = work
SOURCES = main.cpp Bureaucrat.Class.cpp AForm.Class.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp \

OBJECTS = $(SOURCES:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: ${NAME}

%.o: %.c++
	$(CXX) -c $(CXXFLAGS) -g3 $< -o $@ -I

${NAME}: ${OBJECTS}
	$(CXX) $(CXXFLAGS) -g3 -o ${NAME} ${OBJECTS}

clean:
	rm -f ${OBJECTS}
	
fclean: clean
	rm -f ${NAME}

re: fclean all
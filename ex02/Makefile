# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gozon <gozon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/18 11:02:35 by gozon             #+#    #+#              #
#    Updated: 2025/07/15 17:57:44 by gozon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex02
CC = clang++
CFLAGS = -Wall -Wextra -Werror -Wshadow -Wpedantic -std=c++98 -fPIE
CPP =	Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp PresidentialPardonForm.cpp main.cpp
OBJ_DIR = objects
OBJ = $(CPP:%.cpp=$(OBJ_DIR)/%.o)
DEP = $(OBJ:%.o=%.d)

# Symboles Unicode
CHECK_MARK = ✔

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME)
	@echo "$(NAME) a été créé avec succès ($(CHECK_MARK))"

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -MMD -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Nettoyage réussi ($(CHECK_MARK))"

fclean:
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)
	@echo "Nettoyage complet réussi ($(CHECK_MARK))"

re: fclean all

-include $(DEP)
.PHONY: all clean fclean re

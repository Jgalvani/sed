# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/14 17:10:37 by jgalvani          #+#    #+#              #
#    Updated: 2018/10/03 15:19:37 by jgalvani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = replace

SRC_DIR = src

HDR_DIR = hdr

SRCS = main.cpp replace.cpp

HDRS = replace.hpp

OBJ_DIR = objects

OBJS = $(SRCS:.cpp=.o)

SRC_PATH = $(addprefix $(SRC_DIR)/,$(SRCS))
HDR_PATH = $(addprefix $(HDR_DIR)/,$(HDRS))
OBJ_PATH = $(addprefix $(OBJ_DIR)/,$(OBJS))

FLGS = -Wall -Wextra -Werror

.PHONY: all fclean clean re

all: $(NAME)

$(NAME): $(SRC_PATH) $(HDR_PATH)
	@mkdir $(OBJ_DIR) 2> /dev/null || true
	@echo "\033[0;40;32mCreating objects." 2> /dev/null
	@clang++ -c  $(FLGS) $(SRC_PATH)
	@mv $(OBJS) $(OBJ_DIR) 2> /dev/null
	@echo "Compiling" $(NAME) 2> /dev/null
	@clang++ $(FLGS) -o $(NAME) $(OBJ_PATH)
	@echo "\033[0m" 2> /dev/null

clean:
	@echo "\033[0;40;31mErasing objects."
	@rm -rf $(OBJ_PATH) 2> /dev/null
	@rmdir $(OBJ_DIR) 2> /dev/null || true
	@echo "\033[0m" 2> /dev/null

fclean:	clean
	@echo "\033[0;40;35mErasing" $(NAME)
	@rm -rf $(NAME) 2> /dev/null
	@echo "\033[0m" 2> /dev/null

re: fclean all

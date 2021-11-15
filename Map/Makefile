# ************************************************************************************************** #
#                                                                                                    #
#                                                         :::   ::::::::   ::::::::  :::::::::::     #
#    Makefile                                          :+:+:  :+:    :+: :+:    :+: :+:     :+:      #
#                                                       +:+         +:+        +:+        +:+        #
#    By: mamoussa <mamoussa@student.1337.ma>           +#+      +#++:      +#++:        +#+          #
#                                                     +#+         +#+        +#+      +#+            #
#    Created: Invalid date        by                 #+#  #+#    #+# #+#    #+#     #+#              #
#    Updated: 2021/08/10 17:14:13 by mamoussa     ####### ########   ########      ###.ma            #
#                                                                                                    #
# ************************************************************************************************** #

COMPILER = clang++
FLAGS = --std=c++98 -Wall -Wextra -Werror -fsanitize=address -g3

map:
	@$(COMPILER) $(FLAGS)	Map_tests.cpp -o map.out 
clean:
	@rm -rf map.out map.out.dSYM a.out a.out.dSYM

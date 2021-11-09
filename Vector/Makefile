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
FILE = Vector_tests.cpp
FLAGS = --std=c++98 -Wall -Wextra -Werror -fsanitize=undefined
OUT = vector.out
# FLAGS = --std=c++98 -Wall -Wextra -Werror

vector:
	@$(COMPILER) $(FLAGS) $(FILE) -o $(OUT)

map:
	@$(COMPILER) $(FLAGS)	Map_tests.cpp -o map.out 

# stack:
# 	@$(COMPILER) $(FLAGS)	Stack_tests.cpp -o stack.out 

# set:
# 	@$(COMPILER) $(FLAGS)	Set_tests.cpp -o set.out 
clean:
	rm -f vector.out
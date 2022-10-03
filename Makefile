# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elraira- <elraira-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/10 19:09:32 by elraira-          #+#    #+#              #
#    Updated: 2022/09/30 04:27:06 by elraira-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[32m
RESET = \033[0m

NAME		=	philo

PTHREAD		=	-pthread

CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror -fsanitize=thread -g3 -o2
CINC		=	-I $(INCLUDE_PATH)

INCLUDE_PATH 	= ./include/
SRCS_PATH 		= ./src/
OBJS_PATH		= ./philo_objects/

SRCS			=	main.c clean_table.c get_time.c simulation_routine.c\
					parser.c ft_atoi.c ft_putstr_fd.c death_monitoring.c\
					ft_isdigit.c ft_str_isdigit.c check_arguments.c do_action.c\
					display_status.c table_for_one.c philo_sleeping.c\
					philo_thinking.c philo_eating.c check_simulation_end.c\
					start_simulation.c init_program_struct.c ft_putchar_fd.c\
					init_philo_struct.c monitor_routine.c hungry_monitoring.c\
					delay.c

VPATH 			:= $(SRCS_PATH) \
				$(SRCS_PATH)utils \
				$(SRCS_PATH)parsing \
				$(SRCS_PATH)activities \
				$(SRCS_PATH)simulation \
				$(SRCS_PATH)monitoring \

OBJS			=	$(addprefix $(OBJS_PATH), $(notdir $(SRCS:.c=.o)))

$(OBJS_PATH)%.o: %.c
				mkdir -p $(OBJS_PATH)
				$(CC) $(CFLAGS) $(CINC) -c $< -o $@

all:			$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(PTHREAD) $(CINC) -o $(NAME) $(OBJS)
			echo "$(GREEN)Philosophers are ready to eat! 🍝 $(RESET)"

clean:
		rm -rf $(OBJS)
		rm -rf $(OBJS_PATH)

fclean:	clean
		rm -rf $(NAME)
		rm -rf $(OBJS_PATH)

re:		fclean all

PHONY:	all clean fclean re

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:11:42 by elraira-          #+#    #+#             */
/*   Updated: 2022/09/30 14:54:19 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h> // pthread_create, pthread_join, pthread_mutex_lock, etc.
# include <sys/time.h> // gettimeofday
# include <stdio.h> // printf
# include <unistd.h> // usleep, write
# include <stdlib.h> // malloc, free

/*
** Macros
*/
# define INT_MAX 2147483647
# define ARG_MIN 5
# define ARG_MAX 6
# define STDERROR 2

/*
** Error messages macros
*/
# define ARG_NUM_ERROR "Wrong number of arguments.\nUsage: ./philo \
number_of_philosophers time_to_die time_to_eat time_to_sleep \
[number_of_times_each_philosopher_must_eat] (this last one is optional)\n"
# define ARG_VALUE_ERROR "Given arguments must be positive unsigned integers\n"
# define ARG_MAX_ERROR "The maximum number of philosophers is 200\n"
# define GET_TIME_ERROR "An error occurred while getting the current time\n"
# define THREAD_ERROR "An error occurred while creating a thread\n"
# define JOIN_ERROR "An error occurred while joining a thread\n"
# define MUTEX_ERROR "An error occurred while initializing a mutex\n"
# define MALLOC_ERROR "An error occurred while allocating memory\n"

/*
** Activities messages macros
*/
# define TOOK_FORK_MSG "has taken a fork"
# define EATING_MSG "is eating"
# define SLEEPING_MSG "is sleeping"
# define THINKING_MSG "is thinking"
# define DIED_MSG "died"
# define ATE_MSG "Philosophers ate %d times! 🍝 \n"

/*
** enum for the philosopher's status
**
** SIMULATION_ENDED, // defines the end of the simulation - 0
** DIED, // defines that a philosopher died - 1
** THINKING, // defines that a philosopher is thinking - 2
** SLEEPING, // defines that a philosopher is sleeping - 3
** TOOK_FORK, // defines that a philosopher took a fork - 4
** EATING, // defines that a philosopher is eating - 5
*/
enum e_status
{
	SIMULATION_ENDED,
	DIED,
	THINKING,
	SLEEPING,
	TOOK_FORK,
	EATING,
};

/*
** enum for the fork's hand
**
** FIRST_FORK, // defines the left hand - 0
** SECOND_FORK, // defines the right hand - 1
*/
enum e_fork
{
	FIRST_FORK,
	SECOND_FORK,
};

/*
** dinner's struct
**
** int						total_philos; // number of philosophers and forks
** long long int			start; // timestamp of the start of the simulation
** int						time_to_eat; // time spent eating and holding forks
** int						time_to_sleep; // time philo sleeps after eating
** int						time_to_die; // time a philo can live without eating
** int						minimum_meals; // number of times philos must eat
** int						philo_died; // flag to check if a philo died
** pthread_mutex_t			lock_forks; // mutex to lock forks
** pthread_mutex_t			text; // mutex to lock text
*/
typedef struct s_dinner
{
	int						total_philos;
	long long int			start;
	int						time_to_eat;
	int						time_to_sleep;
	int						time_to_die;
	int						minimum_meals;
	int						philo_died;
	pthread_mutex_t			lock_forks;
	pthread_mutex_t			text;
}		t_dinner;

/*
** philosophers' struct
**
** int						index; // index of the philosopher
** int						eaten_times; // number of times the philo ate
** long long int			last_meal; // timestamp of the last meal
** pthread_t				thread; // thread of the philosopher
** pthread_mutex_t			**philo_forks; // forks of the philosopher
** t_dinner					*dinner; // pointer to the dinner struct
*/
typedef struct s_philo {
	int						index;
	int						eaten_times;
	long long int			last_meal;
	pthread_t				thread;
	pthread_mutex_t			**philo_forks;
	t_dinner				*dinner;
}	t_philo;

/*
** program's struct
**
** pthread_mutex_t			**philo_forks; // forks of the philosophers
** t_philo					**philo; // struct of the philosophers info
** t_dinner					dinner; // struct with the dinner info
*/
typedef struct s_program {
	pthread_mutex_t			**philo_forks;
	t_philo					**philo;
	t_dinner				dinner;
}	t_program;

/*
** libft functions
*/

int							ft_atoi(const char *str);
int							ft_isdigit(int c);
int							ft_str_isdigit(char *str);
void						ft_putchar_fd(char c, int fd);
void						ft_putstr_fd(const char *s, int fd);

/*
** other utils functions
*/

long long int				get_time(void);
void						display_status(t_philo *philo, int status);
void						do_action(long long int time);
void						delay(double time_to_delay);

/*
** parser functions
*/

int							check_arguments(int argc, char **argv);
int							parser(t_program *program, char **argv, int argc);
int							init_program_struct(t_program *program,
								char **argv, int argc);
int							init_philo_struct(t_program *program);

/*
** activities functions
*/

void						philo_sleeping(t_philo *philo);
void						philo_thinking(t_philo *philo);
int							philo_eating(t_philo *philo);

/*
** simulation functions
*/
void						clean_table(t_program *program);
int							start_simulation(t_program *program);
void						*routine(void *program);
int							check_simulation_end(t_philo *philo);
void						table_for_one(t_philo *philo);

/*
** monitoring functions
*/
void						*monitor_routine(void *philo);
int							hungry_monitoring(t_philo **monitor,
								t_dinner *dinner);
int							death_monitoring(t_philo **monitor,
								t_dinner *dinner);

#endif

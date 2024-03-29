/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:54:22 by ldevy             #+#    #+#             */
/*   Updated: 2022/09/26 19:36:56 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

struct	s_info;
typedef enum s_states
{
	WAIT,
	EATING,
	SLEEPING,
	THINKING,
	DEAD
}	t_state;
typedef struct s_philo
{
	pthread_t		tid;
	int				numero;
	long long		time_die;
	long long		last_eat;
	int				l_fork;
	int				r_fork;
	int				nb_meals;
	t_state			etat;
	struct s_info	*info;
}	t_philo;

typedef struct s_info
{
	long long		time_die;
	long long		time_eat;
	long long		time_sleep;
	long long		start;
	int				nb_philo;
	int				cycles;
	int				end;
	int				phi_died;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
	pthread_mutex_t	state;
	pthread_mutex_t	leat;
	pthread_mutex_t	bonus;
	pthread_mutex_t	ntm;
}	t_info;

//threads
int			start_threads(t_info *u);
void		end_threads(t_info *info);

//utils_one
int			ft_isdigit(char c);
int			ft_atoi(char *str);
long long	time_stamp(long long start_time);
long long	last_since(long long before);

//routine_one
void		ft_sleep(t_philo *philo);
void		eat_pone(t_philo *philo);
void		eat_ptwo(t_philo *philo);
void		think(t_philo *philo);
void		log_display(t_philo *philo);
void		*mdr(void *philo);
void		death_check_extention(t_info *info, int i);

//routine_two
int			death_check(t_info *info);
int			all_ate(t_info *in);

//init_one
int			init_info(int argc, char **args, t_info *info);
int			init_philo(t_info *info);
int			init_mutex(t_info *info);
void		init_time(t_info *info);
int			info_check(t_info i);
int			init_mutex_extention(t_info *info);

//mem_management
void		end_all(t_info *info);

//debug
void		show_phi(t_philo phi);

//correction
int			args_full_check(int argc, char **argv);
void		solo_phi(char *str);
int			solo_case(int argc, char **argv);

#endif
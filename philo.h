/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:54:22 by ldevy             #+#    #+#             */
/*   Updated: 2022/09/06 16:17:52 by ldevy            ###   ########.fr       */
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
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
}	t_info;

//utils_one
int			ft_atoi(char *str);
long long	time_stamp(long long start_time);

//routine
void		ft_sleep(t_philo *philo);
void		eat(t_philo *philo);
void		think(t_philo *philo);
void		log_display(t_philo philo);
void		*mdr(void *philo);

//init_one
int			init_info(int argc, char **args, t_info *info);
int			init_philo(t_info *info);
int			init_mutex(t_info *info);

//mem_management
void		end_all(t_info *info);

//debug
void		show_phi(t_philo phi);

#endif
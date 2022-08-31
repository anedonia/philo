/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:54:22 by ldevy             #+#    #+#             */
/*   Updated: 2022/08/31 17:50:20 by ldevy            ###   ########.fr       */
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

int	ft_atoi(char *str);

typedef struct s_philo
{
	pthread_t		tid;
	int				numero;
	struct timeval	time_die;
	struct timeval	last_eat;
	//t_state			etat;
}	t_philo;

typedef struct s_info
{
	struct timeval	time_die;
	struct timeval	time_eat;
	struct timeval	time_sleep;
	struct timeval	start;
	int				nb_philo;
	int				cycles;
	t_philo			*philo;
}	t_info;

typedef enum s_states
{
	WAIT,
	EATING,
	SLEEPING,
	THINKING,
	DEAD
}	t_state;



#endif
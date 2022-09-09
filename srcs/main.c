/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:31:58 by ldevy             #+#    #+#             */
/*   Updated: 2022/09/09 16:05:35 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	test_threads(t_info *info)
{
	int	i;
	int	state;
	struct timeval	start;

	i = 0;
	gettimeofday(&start, NULL);
	info->start = start.tv_sec * 1000 + start.tv_usec / 1000;
	while (i < info->nb_philo)
	{
		state = pthread_create(&(info->philo[i].tid), NULL, mdr, &(info->philo[i]));
		if (state != 0)
			return ;
		i++;
	}
	death_check(info);
	i = 0;
	while (i < info->nb_philo)
	{
		state = pthread_join(info->philo[i].tid, NULL);
		if (state != 0)
			return ;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_info	info;

	init_info(argc, argv, &info);
	test_threads(&info);
	return (0);
}

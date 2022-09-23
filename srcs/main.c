/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:31:58 by ldevy             #+#    #+#             */
/*   Updated: 2022/09/20 21:55:52 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	start_threads(t_info *u)
{
	int				i;
	struct timeval	start;

	i = 0;
	gettimeofday(&start, NULL);
	u->start = start.tv_sec * 1000 + start.tv_usec / 1000;
	init_time(u);
	while (i < u->nb_philo)
	{
		if (pthread_create(&(u->philo[i].tid), NULL, mdr, &(u->philo[i])) != 0)
			return (1);
		i++;
	}
	death_check(u);
	end_threads(u);
	return (0);
}

void	end_threads(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nb_philo)
	{
		if (pthread_join(info->philo[i].tid, NULL) != 0)
			return ;
		i++;
	}
	end_all(info);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 5 && argc != 6)
	{
		printf("number of args invalid\n");
		return (1);
	}
	if (ft_atoi(argv[1]) == 1 && solo_case(argc, argv))
		return (4);
	if (init_info(argc, argv, &info))
		return (2);
	if (start_threads(&info))
	{
		printf("issue in thread creation\n");
		return (3);
	}
	return (0);
}

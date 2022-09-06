/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:31:58 by ldevy             #+#    #+#             */
/*   Updated: 2022/09/06 16:21:23 by ldevy            ###   ########.fr       */
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

// int	main(int argc, char **argv)
// {
// 	struct timeval	start;
// 	struct timeval	end;

// 	(void)argc;
// 	(void)argv;
// 	for (int i = 0; i < 10; i++)
// 	{
// 		gettimeofday(&start, NULL);
// 		usleep(20000);
// 		gettimeofday(&end, NULL);
// 		printf("time diff : %ld\n", end.tv_usec - start.tv_usec);
// 		printf("start : %ld end %ld\n", start.tv_usec, end.tv_usec);
// 	}
// 	return (0);
// }

//il faut faire attention usleep est en micro sec pas milli
//les fourchettes sont un tableau daddr partagé entre les threads 
//on peut les différenciers avec 0 ou 1 pour signifier leur etat ?

//besoin de start le temps une fois au debut 
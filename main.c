/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amecani <amecani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:02:39 by amecani           #+#    #+#             */
/*   Updated: 2024/06/29 20:44:51 by amecani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void think(t_phedo *phedo)
// {
// 	usleep(phedo->info->hungyy);
// 	display_action(phedo, "is thinking");
// }

// void eat(t_phedo *phedo)
// {
// 	pthread_mutex_lock(&phedo->l_frok);
// 	pthread_mutex_lock(phedo->r_frok);
// 	usleep(phedo->info->hungyy);
// 	if (phedo->info->state != DEATH \
// 	&& get_time() - phedo->last_reset > phedo->info->die2time)
// 	{
// 		phedo->info->state = -69;
// 		phedo->info->dead_person = phedo->id;
// 		phedo->info->time_of_death = get_time() - phedo->born;
// 	}
// 	display_action(phedo, "has taken a fork");
// 	display_action(phedo, "has taken a fork");
// 	phedo->last_reset = get_time();
// 	pthread_mutex_unlock(&phedo->l_frok);
// 	pthread_mutex_unlock(phedo->r_frok);
// }

// void sleepin(t_phedo *phedo)
// {
// 	display_action(phedo, "is sleeping");
// 	usleep(phedo->info->zzzz);
// }

void	*routine(void *yey)
{
	t_phedo *phedo;
	// int i = 0;

	phedo = yey;
	// phedo->born =  get_time();
	// phedo->last_reset = get_time();
	// if (phedo->id % 2 || phedo->id == 1)
	// 	think(phedo);
	// while (i < phedo->info->pasta_overload)
	// {
	// 	eat(phedo);
	// 	sleepin(phedo);
	// 	display_action(phedo, "is thinking");
	// 	i++;
	// }
	return (NULL);
}

// int start(t_info *info)
// {
// 	int i = 0;

// 	while (i < info->philos)
// 	{
// 		if(pthread_create(info->phedo[i].thread, NULL, &routine, &info->phedo[i]))
// 			return (1); // destryoy all shits and free
// 		i++;
// 	}
// 	i = 0;
// 	while (i < info->philos)
// 	{
// 		if (pthread_join(*info->phedo[i].thread, NULL))
// 			put_str("Thread joibing fialed\n");// destroy everythin
// 		i++;
// 	}
// 	if (info->state == DEATH)
// 	{
// 		put_str(ft_itoa(info->die2time));
// 		put_c(' ');
// 		put_str(ft_itoa(info->dead_person));
// 		put_c(' ');
// 		put_str(" died\n");
// 	}
// 	return (0);
// }

int	main(int ac, char **av)
{
	t_info	info;
	t_phedo *phedos;

	if (!inserting_args(av, ac, &info)) //  all the info is initialized here
		return (1);
	if (!init_mutexes(&info))  // the mutexes are initialized
		return (1);
	if (!init_phedos(&phedos, &info)) // phedos aint lifting froks properly
		return (1);
	if (!stitch_it_boyyy(&info, phedos)) // phedos aint stiching yet
		return (1);
	// start(info);
	return (0);
}

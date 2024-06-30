/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amecani <amecani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:02:39 by amecani           #+#    #+#             */
/*   Updated: 2024/06/30 20:44:45 by amecani          ###   ########.fr       */
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

void	ft_usleep(int time)
{
	long long	start;
	// long long	end;
	// long long	now;

	// start = get_time();
	// end = start + time;
	// while (1)
	// {
	// 	now = get_time();
	// 	if (now >= end)
	// 		break ;
	// 	usleep(100);
	// }
	/////////////////////
	// Same shit but looks simplerr
	start = get_time();
	while (get_time() < start + time)
		usleep(100);
}

void	phedo_eating(t_phedo *phedo)
{
	// printf("EATINH");
	pthread_mutex_lock(&phedo->r_frok);
	display_action(phedo, "has taken a fork");
	if (phedo->info->philos > 1)
	{
		pthread_mutex_lock(phedo->l_frok);
		display_action(phedo, "has taken a fork");
		pthread_mutex_lock(&phedo->lock_hungyy);
		display_action(phedo, "is eating");
		phedo->last_reset = get_time();
		phedo->numnum_count++;
		if (phedo->numnum_count == (int)phedo->info->pasta_overload)
			phedo->completion = 1;
		ft_usleep(phedo->info->hungyy);
		pthread_mutex_unlock(&phedo->lock_hungyy);
		pthread_mutex_unlock(&phedo->r_frok);
		pthread_mutex_unlock(phedo->l_frok);
	}
	else
		pthread_mutex_unlock(&phedo->r_frok);
}

void	phedo_being_stubid(t_phedo	*phedo)
{
	display_action(phedo, "is sleeping");
	ft_usleep(phedo->info->zzzz);
	if (!phedo->info->state || phedo->info->no_crumbs_left)
		return ;
	display_action(phedo, "is thinking");
	return ;
}

void	*routine(void *yey)
{
	t_phedo	*phedo;

	// int i = 0;
	phedo = (t_phedo *)yey;
	if (phedo->id % 2 == 0 || phedo->info->philos == phedo->id)
	{
		display_action(phedo, "is thinking");
		ft_usleep(phedo->info->hungyy);
	}
	// printf("\nDEBUG\n\n");
	// while (phedo->info->state)
	while ("my laywer advised me not to proceed with the joke")
	{
		if (!phedo->info->state || phedo->info->no_crumbs_left)
			return (NULL);
		phedo_eating(phedo);
		if (!phedo->info->state || phedo->info->no_crumbs_left)
			return (NULL);
		phedo_being_stubid(phedo);
		if (!phedo->info->state || phedo->info->no_crumbs_left)
			return (NULL);
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	t_info	info;
	t_phedo	*phedos;

	if (!inserting_args(av, ac, &info)) //  all the info is initialized here
		return (1);
	// printf("1 \n");
	if (!init_mutexes(&info)) // the mutexes are initialized
		return (1);
	// printf("2 \n");
	if (!init_phedos(&phedos, &info)) // phedos aint lifting froks properly
		return (1);
	// printf("3 \n");
	if (!stitch_it_boyyy(&info, phedos)) // phedos aint stiching yet
		return (1);
	// printf("4 adssd \n");
	// start(info);
	return (0);
}

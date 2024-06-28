/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amecani <amecani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:02:39 by amecani           #+#    #+#             */
/*   Updated: 2024/06/28 12:34:15 by amecani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void think(t_phedo *phedo)
{
	usleep(phedo->info->hungyy);
	display_action(phedo, "is thinking");
}

void eat(t_phedo *phedo)
{
	pthread_mutex_lock(&phedo->l_frok);
	pthread_mutex_lock(phedo->r_frok);
	display_action(phedo, "has taken a fork");
	display_action(phedo, "has taken a fork");
	phedo->last_reset = get_time();
	pthread_mutex_unlock(&phedo->l_frok);
	pthread_mutex_unlock(phedo->r_frok);
}

void sleepin(t_phedo *phedo)
{
	display_action(phedo->id, "is sleeping");
	usleep(phedo->info->zzzz);
}

void	*routine(void *yey)
{
	t_phedo *phedo;
	int i = 0;

	phedo = yey;
	phedo->birthday =  
	phedo->last_reset = get_time();
	if (phedo->id % 2 || phedo->id == 1)
		think(phedo);
	while (i < phedo->info->pasta_overload)
	{
		eat(phedo);
		sleepin(phedo);
		display_action(phedo, "is sleeping");
		i++;
	}
	return NULL;
}

int start(t_i *info)
{
	int i = 0;

	while (i < info->philos)
	{
		if(pthread_create(info->phedo[i].thread, NULL, &routine, &info->phedo[i]))
			return (1); // destryoy all shits and free
		i++;
	}
}

int	main(int ac, char **av)
{
	t_i	*info;

	info = NULL;
	if (!inserting_args(av, ac, &info))
		return (1);
	if (!init_stuff(info))
		return (1);
	start(info);
}

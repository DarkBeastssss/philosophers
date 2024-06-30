/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amecani <amecani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:02:39 by amecani           #+#    #+#             */
/*   Updated: 2024/06/30 21:34:18 by amecani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(int time)
{
	long long	start;

	start = get_time();
	while (get_time() < start + time)
		usleep(100);
}

void	phedo_eating(t_phedo *phedo)
{
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

	phedo = (t_phedo *)yey;
	if (phedo->id % 2 == 0 || phedo->info->philos == phedo->id)
	{
		display_action(phedo, "is thinking");
		ft_usleep(phedo->info->hungyy);
	}
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

	if (!inserting_args(av, ac, &info))
		return (1);
	if (!init_mutexes(&info))
		return (1);
	if (!init_phedos(&phedos, &info))
		return (1);
	if (!stitch_it_boyyy(&info, phedos))
		return (1);
	return (0);
}

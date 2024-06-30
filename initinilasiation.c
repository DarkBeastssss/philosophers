/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initinilasiation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amecani <amecani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 23:22:23 by amecani           #+#    #+#             */
/*   Updated: 2024/06/30 20:27:26 by amecani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutexes(t_info *info)
{
	if (pthread_mutex_init(&info->lock_done, NULL) != 0)
		return (printf("lock_dead faillll!"), 0);
	if (pthread_mutex_init(&info->lock_dead, NULL) != 0)
		return (pthread_mutex_destroy(&info->lock_done),
			printf("lock_done faillll!\n"), 0);
	if (pthread_mutex_init(&info->lock_print, NULL) != 0)
		return (pthread_mutex_destroy(&info->lock_dead), \
		pthread_mutex_destroy(&info->lock_done), printf("lock_printy faillll!\n"), 0);
	return (1);
}

int	inserting_args(char **av, int ac, t_info *info)
{
	if (ac != 5 && ac != 6)
		return (put_str("Provide :\n\
	(1) number_of_philosophers\n\
	(2) time_to_die\n\
	(3) time_to_eat\n\
	(4) time_to_sleep\n\
	(5) (optional) number_of_times_each_philosopher_must_eat\n\
	THE NUMBER WILL BE CUT OF FROM THE REST OF ARG IF NON-DIGIT PROVIDED (atoi)\n"),
				0);
	if (!ft_atoi(av[1]))
		return (put_str("Values cannot be zero\n"), 0);
	if (ac == 6 && !ft_atoi(av[5]))
		return (put_str("Values cannot be zero\n"), 0);
	(info)->pasta_overload = -1;
	(info)->philos = ft_atoi(av[1]);
	(info)->die2time = ft_atoi(av[2]);
	(info)->hungyy = ft_atoi(av[3]);
	(info)->zzzz = ft_atoi(av[4]);
	(info)->state = 1;
	(info)->start_t = get_time();
	if (ac == 6)
		(info)->pasta_overload = ft_atoi(av[5]);
	return (1);
}

int	phedo_init(t_phedo *phedo, int id, t_info *info)
{
	phedo->id = id +1;
	phedo->die_to_time = info->die2time;
	phedo->numnum_count = 0;
	phedo->last_reset = info->start_t;
	phedo->completion = 0;
	phedo->info = info;
	return (1);
}

void	destroy_phedo(t_phedo **philos, int id)
{
	while (id > 0)
	{
		id--;
		pthread_mutex_destroy(&(*philos)[id].r_frok);
		pthread_mutex_destroy(&(*philos)[id].lock_hungyy);
	}
	free(*philos);
}

int	init_phedos(t_phedo **phedos, t_info *info)
{
	int	id;

	id = -1;
	*phedos = malloc(sizeof(t_phedo) * info->philos);
	if(!phedos)
		return(printf("Aint mallocin' cuh!\n"));
	while (++id < info->philos)
	{
		phedo_init(&(*phedos)[id], id, info);
		if (pthread_mutex_init(&(*phedos)[id].r_frok, NULL) != 0)
			return (destroy_phedo(phedos, id),
				printf("r_fork aint forkin\n"), 0);
		if (pthread_mutex_init(&(*phedos)[id].lock_hungyy, NULL) != 0)
			return (pthread_mutex_destroy(&(*phedos)[id].r_frok),
				destroy_phedo(phedos, id),
				printf("lock_eating doesnt want to lock\n"), 0);
		if (id)
			(*phedos)[id].l_frok = &(*phedos)[id - 1]. r_frok;
	}
	if (info->philos <= 1)
		return (1);
	(*phedos)[0].l_frok = &(*phedos)[info->philos - 1].r_frok;
	return (1);
}

void	*tummy_check(void *phedos)
{
	t_phedo	*phedo;
	int		full;
	int		i;

	phedo = phedos;
	while (1)
	{
		i = -1;
		full = 0;
		while (++i < phedo->info->philos)
		{
			if (phedo[i].completion == 1)
				full++;
		}
		if (full == phedo->info->philos)
			return (phedo->info->no_crumbs_left = 1, NULL);
		if (!phedo->info->state)
			return (NULL);
		// usleep(5);
		usleep(10);
	}
	return (NULL);
}

void	phedo_in_hell(t_phedo *phedo, long long time)
{
	pthread_mutex_lock(&phedo->info->lock_print);
	phedo->info->state = 0;
	printf("%lld %d died\n", time - phedo->info->start_t, phedo->id);
	usleep(100);
	pthread_mutex_unlock(&phedo->info->lock_print);
	pthread_mutex_unlock(&phedo->info->lock_dead);
}

void	*death_check(void *phedos)
{
	t_phedo		*phedo;
	long long	time;
	int			id;

	phedo = phedos;
	id	= -1;
	while (++id < phedo->info->philos)
	{
		pthread_mutex_lock(&phedo[id].info->lock_dead);
		time = get_time();
		if (phedo[id].die_to_time <= time - phedo[id].last_reset)
		{
			return (phedo_in_hell(&phedo[id], time), NULL);
		}
		pthread_mutex_unlock(&phedo[id].info->lock_dead);
		if(phedo->info->no_crumbs_left == 1)
			return (NULL);
		if (id == phedo->info->philos - 1)
			id = -1;
	}
	return (NULL);
}

int	stitch_it_boyyy(t_info *info, t_phedo *phedos)
{
	int			id;
	pthread_t	dead;
	pthread_t	tummy_burst;

	phedos->info->no_crumbs_left = 0;
	phedos->info->state = 1;
	pthread_create(&dead, NULL, death_check, phedos);
	pthread_create(&tummy_burst, NULL, tummy_check, phedos);
	id = 0;
	while (id < info->philos)
	{
		if (pthread_create(&phedos[id].thread, NULL, routine, &phedos[id]))
			return (put_str("Thread Creation Fault\n"), 0);
		id++;
	}
	id = -1;
	while (++id < info->philos)
		pthread_join(phedos[id].thread, NULL);
	return (1);
}

// int	init_stuff(t_info *info)
// {
// 	t_phedo	*phedo;

// 	int		i = 0;

// 	phedo = malloc(sizeof(t_phedo)* info->philos);
// 	if (!phedo)
// 		return(put_str("maloc fail for philos, cclean bro"));
// 	// i need to malloc memory for lock_print first, dam
// 	info->lock_print = malloc(sizeof(pthread_mutex_t));
// 	info->lock_dead = malloc(sizeof(pthread_mutex_t));
// 	if (pthread_mutex_init(info->lock_print, NULL) != 0 || \
// 		pthread_mutex_init(info->lock_dead, NULL) != 0)
// 		return (put_str("Error_p1\n"));
			// why the fuck is phedo 0? didnt i just mallocate it
// 	while (i < info->philos)			// is it cuz of calloc?
// 	{
// 		if (i == 0)
// 		{
// 			pthread_mutex_init(&info->phedo[i].l_frok, NULL);
// 			info->phedo[0].r_frok = NULL;
// 		}
// 		else
// 		{
// 			pthread_mutex_init(&info->phedo[i].l_frok, NULL);
// 			info->phedo[i-1].r_frok = &info->phedo[i].l_frok;
// 		}
// 		// if (i + 1 == info->philos)
// 		// {
// 		// 	info->phedo[i].r_frok = &info->phedo[0].l_frok;
// 		// 	printf("hereeee\n");
// 		// }
// 		// else
// 		// {
// 		// 	printf("heeeee_1\n");
// 		// 	pthread_mutex_init(&info->phedo[i].l_frok, NULL);
// 		// 	pthread_mutex_init(&info->phedo[i+1].l_frok, NULL);
// 		// 	info->phedo[i].r_frok = &info->phedo[i + 1].l_frok;
// 		// }
// 		// other initinialisations
// 		phedo[i].id = i + 1;
// 		phedo[i].info = info;
// 		i++;
// 	}//philos yes
// 	return (1);
// }

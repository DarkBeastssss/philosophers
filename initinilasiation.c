/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initinilasiation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amecani <amecani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 23:22:23 by amecani           #+#    #+#             */
/*   Updated: 2024/06/29 07:23:44 by amecani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		return (put_str("Values cannot be zero"), 0);
	if (ac == 6 && !ft_atoi(av[5]))
		return (put_str("Values cannot be zero"), 0);
	// (*info) = ft_calloc(1, sizeof(t_info));
	// if (!info)
		// return (put_str("Malloc failed"), 0);
	(info)->pasta_overload = -1; // half half but fuck it
	(info)->philos = ft_atoi(av[1]);
	(info)->die2time = ft_atoi(av[2]);
	(info)->hungyy = ft_atoi(av[3]);
	(info)->zzzz = ft_atoi(av[4]);
	(info)->is_dead = 0;
	if (ac == 6)
		(info)->pasta_overload = ft_atoi(av[5]);
	init_mutexes(info);
	return (1);
}

// while (i < phedo->info->philos)
// 	pthread_mutex_init(&phedo[i++].l_frok, NULL);
// i = 1;
// while (i < phedo->info->philos)
// {
// 	if (i + 1 == phedo->info->philos)
// 		phedo[0].r_frok = &phedo[i].l_frok;
// 	else
// 		phedo[i - 1].r_frok = &phedo[i].l_frok;
// }

int	init_mutexes(t_info *info)
{
	if (pthread_mutex_init(&info->lock_dead, NULL) != 0)
		return (printf("destroy not done"), 0);
	if (pthread_mutex_init(&info->lock_done, NULL) != 0)
		return (printf("destroy not done"), 0);
	if (pthread_mutex_init(&info->lock_print, NULL) != 0)
		return (printf("destroy not done"), 0);
	return (1);
}

int	init_phedos(t_info *info)
{
}

int	init_stuff(t_info info)
{
	pthread_t	dead;
	pthread_t	full;
	t_phedo		*phedo;
	int			id;

	init_phedos(info);
	id = 0;
	while (id < info->philos)
	{
		if (pthread_create(&phedo[id].thread, NULL, routine, &info->phedo[i]))
			
	}
	
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amecani <amecani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:02:44 by amecani           #+#    #+#             */
/*   Updated: 2024/06/28 16:27:21 by amecani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/time.h>

// assuming everything would be fine I need to do the free/destryo

typedef struct s_info
{
	pthread_mutex_t	*lock_print;
	pthread_mutex_t	*lock_dead;
	int		philos;
	int		die2time;
	int		hungyy;
	int		zzzz;
	int		pasta_overload;
	bool	state;
	long	time_of_death;
	int		dead_person;
	t_phedo		*phedo;
}	t_i;

typedef struct s_phedo
{
	pthread_t		*thread;
	t_i				*info;
	int				id;
	long			last_reset;
	long			born;
	pthread_mutex_t	l_frok;
	pthread_mutex_t	*r_frok;
}	t_phedo;

#ifndef philosopher
# define philosopher

# include <stdlib.h>
# include <stdio.h>

# define DEATH		-69

long long	ft_atoi(const char *bomba);
int			inserting_args(char **av, int ac, t_i **info);
int			init_stuff(t_i *info);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
void		think(t_phedo *phedo);
void		eat(t_phedo *phedo);
void		 sleepin(t_phedo *phedo);
void		*routine(void *yey);
int			start(t_i *info);
long		get_time(void);
void		display_action(t_phedo *phedo ,char *string);
void		put_c(char c);
void		put_str(char *s);

#endif
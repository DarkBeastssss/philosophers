/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amecani <amecani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:02:44 by amecani           #+#    #+#             */
/*   Updated: 2024/06/30 21:18:00 by amecani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_phedo	t_phedo;

typedef struct s_info
{
	pthread_mutex_t		lock_print;
	pthread_mutex_t		lock_dead;
	pthread_mutex_t		lock_done;
	int					no_crumbs_left;
	int					philos;
	int					die2time;
	int					hungyy;
	int					zzzz;
	int					pasta_overload;
	int					state;
	t_phedo				*phedo;
	long long			start_t;
}						t_info;

struct					s_phedo
{
	pthread_t			thread;
	t_info				*info;
	int					id;
	long				last_reset;
	long				born;
	int					die_to_time;
	int					numnum_count;
	int					completion;
	pthread_mutex_t		*l_frok;
	pthread_mutex_t		r_frok;
	pthread_mutex_t		lock_hungyy;
};

# define DEATH 0

long long				ft_atoi(const char *bomba);
int						inserting_args(char **av, int ac, t_info *info);
int						init_phedos(t_phedo **phedos, t_info *info);
void					ft_bzero(void *s, size_t n);
void					*ft_calloc(size_t count, size_t size);
int						stitch_it_boyyy(t_info *info, t_phedo *phedos);
int						init_mutexes(t_info *info);
void					*routine(void *yey);
int						start(t_info *info);
long long				get_time(void);
void					display_action(t_phedo *phedo, char *string);
void					put_c(char c);
int						put_str(char *s);
char					*ft_itoa(int n);
char					*ft_strdup(const char *s1);
int						ft_strlen(char *s);

#endif
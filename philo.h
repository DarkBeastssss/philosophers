/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amecani <amecani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:02:44 by amecani           #+#    #+#             */
/*   Updated: 2024/06/29 07:21:51 by amecani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/time.h>
#include <limits.h>

// assuming everything would be fine I need to do the free/destryo
typedef struct s_phedo t_phedo;

typedef struct s_info
{
	pthread_mutex_t	*lock_print;
	pthread_mutex_t	*lock_dead;
	pthread_mutex_t	*lock_done;
	int				philos; //number of philos
	int				die2time; // death timer
	int				hungyy; // time to eat
	int				zzzz; // time to sleep
	int				pasta_overload; // number of times to eat
	int				state; // dead ? alive
	// These two down are to capture the first one to die
	long			time_of_death; // penis
	int				dead_person; // blass
	int				is_dead;
	t_phedo			*phedo;
}	t_info;

struct s_phedo
{
	pthread_t		*thread;	//done
	t_info			*info;		//
	int				id;			//
	long			last_reset;	//
	long			born;		//
	pthread_mutex_t	l_frok;		//done
	pthread_mutex_t	*r_frok;	//done
};

#ifndef philosopher
# define philosopher

# include <stdlib.h>
# include <stdio.h>

# define DEATH		-69

long long	ft_atoi(const char *bomba);
int			inserting_args(char **av, int ac, t_info *info);
int			init_stuff(t_info info);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
void		think(t_phedo *phedo);
void		eat(t_phedo *phedo);
void		 sleepin(t_phedo *phedo);
void		*routine(void *yey);
int			start(t_info *info);
long		get_time(void);
void		display_action(t_phedo *phedo ,char *string);
void		put_c(char c);
int			put_str(char *s);
char		*ft_itoa(int n);
char		*ft_strdup(const char *s1);
int			ft_strlen(char *s);

#endif
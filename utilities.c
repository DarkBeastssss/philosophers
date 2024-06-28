#include "philo.h"

long	get_time(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void display_action(t_phedo *phedo ,char *string)
{
	if (phedo->info->state == DEATH)
		return;
	pthread_mutex_lock(phedo->info->lock_print);
	put_str(ft_atoi(get_time()));
	put(' ');
	put_str(ft_atoi(phedo->id));
	put(' ');
	put_str(string);
	put('\n');
	pthread_mutex_unlock(phedo->info->lock_print);
}

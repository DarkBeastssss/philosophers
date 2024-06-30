#include "philo.h"

long long	get_time(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return ((long long)(time.tv_sec * 1000) + (time.tv_usec / 1000));
}

// void display_action(t_phedo *phedo ,char *string)
// {
// 	pthread_mutex_lock(&phedo->info->lock_print);
// 	if (!phedo->info->state)
// 	{
// 		pthread_mutex_unlock(&phedo->info->lock_print);
// 		return ;
// 	}
// 	put_str(ft_itoa(get_time() - phedo->born));
// 	put_c(' ');
// 	put_str(ft_itoa(phedo->id));
// 	put_c(' ');
// 	put_str(string);
// 	put_c('\n');
// 	// printf("here\n");
// 	pthread_mutex_unlock(&phedo->info->lock_print);
// }

void	display_action(t_phedo *phedo ,char *string)
{
	long long	timestamp;

	pthread_mutex_lock(&phedo->info->lock_print);
	if (!phedo->info->state)
	{
		pthread_mutex_unlock(&phedo->info->lock_print);
		return ;
	}
	timestamp = get_time() - phedo->info->start_t;
	printf("%lld %d %s\n", timestamp, phedo->id, string);
	pthread_mutex_unlock(&phedo->info->lock_print);
}

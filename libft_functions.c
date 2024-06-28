/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amecani <amecani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 23:22:18 by amecani           #+#    #+#             */
/*   Updated: 2024/06/28 17:52:29 by amecani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_atoi(const char *bomba)
{
	int	i;
	int	charge;
	int	result;

	i = 0;
	charge = 1;
	result = 0;
	while (bomba[i] && (bomba[i] == ' ' || bomba[i] == '\t'
			|| bomba[i] == '\n' || bomba[i] == '\r'
			|| bomba[i] == '\f' || bomba[i] == '\v'))
		i++;
	if (bomba[i] && (bomba[i] == '-' || bomba[i] == '+'))
	{
		if (bomba[i] == '-')
		{
			charge *= -1;
		}
		i++;
	}
	while (bomba[i] && (bomba[i] <= '9' && bomba[i] >= '0'))
	{
		result = result * 10 + (bomba[i] - 48);
		i++;
	}
	return (result * charge);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*u;

	u = (char *)s;
	i = 0;
	while (i < n)
	{
		u[i++] = '\0';
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (!(ptr))
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

void	put_c(char c)
{
	write (1, &c, 1);
}

int	put_str(char *s)
{
	int i;

	i = 0;
	while (s[i])
		put_c(s[i++]);
	return 0;
}

int	ft_strlen(char *s)
{
	int	i = 0;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	i;
	size_t	cj;

	cj = ft_strlen((char *)s1);
	i = 0;
	ptr = malloc(sizeof(char) * cj + 1);
	if (!ptr)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static int	size_finer(long long l)
{
	int	digits;

	digits = 0;
	if (!l)
		return (1);
	if (l < 0)
	{
		l = -l;
		digits++;
	}
	while (l)
	{
		digits++;
		l = l / 10;
	}
	return ((int)digits);
}

char	*ft_itoa(int n)
{
	long long	l;
	char		*ptr;
	int			size;

	if (!n)
		return (ft_strdup("0"));
	l = n;
	size = size_finer(l);
	ptr = (char *)malloc(size + 1);
	if (!ptr)
		return (NULL);
	if (n < 0)
	{
		ptr[0] = '-';
		l = -l;
	}
	ptr[size] = '\0';
	while ((size || l) && l > 0)
	{
		size--;
		ptr[size] = (l % 10) + 48;
		l = l / 10;
	}
	return (ptr);
}
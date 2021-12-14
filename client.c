/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:49:54 by bepifani          #+#    #+#             */
/*   Updated: 2021/12/14 14:19:09 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_b = 0;

void	ft_massege(int a)
{
	if (a == SIGUSR1)
		g_b = 1;
}

void	ft_sending(int pid, int massege)
{
	int	j;

	j = 7;
	usleep(100);
	while (j >= 0)
	{
		if (massege & 1 << j)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		j--;
		usleep(100);
		while (g_b == 0)
			usleep(1);
	}
}

int	main(int argc, char **argv)
{
	int		pid1;
	int		i;

	if (argc != 3)
	{
		write(1, "error\n", 6);
		return (0);
	}
	pid1 = ft_atoi(argv[1]);
	i = 0;
	signal(SIGUSR1, ft_massege);
	while (argv[2][i] != '\0')
	{
		ft_sending(pid1, argv[2][i]);
		i++;
	}
	ft_sending(pid1, '\0');
}

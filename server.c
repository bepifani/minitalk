/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:50:07 by bepifani          #+#    #+#             */
/*   Updated: 2021/12/14 14:26:06 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_action_handler(int sig, siginfo_t *info, void *text)
{
	static int	c_pid;
	static int	bit;
	static int	c;

	(void)text;
	if (!c_pid || c_pid != info->si_pid)
	{
		c_pid = info->si_pid;
		bit = 0;
		c = 0;
	}
	if (sig == SIGUSR1)
		c += 1 << (7 - bit);
	bit++;
	if (bit == 8)
	{
		if (c != 0)
			write (1, &c, 1);
		else
			write (1, "\n", 1);
		bit = 0;
		c = 0;
	}
	kill(c_pid, SIGUSR1);
}

void	ft_pid(int pid)
{
	char	c;

	if (!pid)
		return ;
	ft_pid(pid / 10);
	c = pid % 10 + '0';
	write(1, &c, 1);
}

int	main(void)
{
	int					pid;
	struct sigaction	a;

	a.sa_flags = SA_SIGINFO;
	a.sa_sigaction = ft_action_handler;
	sigaction(SIGUSR1, &a, NULL);
	sigaction(SIGUSR2, &a, NULL);
	pid = getpid();
	write(1, "PID: ", 5);
	ft_pid(pid);
	write (1, "\n", 1);
	while (1)
		pause();
	return (0);
}

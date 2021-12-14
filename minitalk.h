/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:31:19 by bepifani          #+#    #+#             */
/*   Updated: 2021/12/14 14:27:15 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

int			ft_atoi(const char *str);
void		myint(int sig);
void		ft_sending(pid_t pid, int massege);
void		ft_massege(int a);
void		ft_action_handler(int sig, siginfo_t *info, void *text);
void		ft_pid(int pid);

#endif
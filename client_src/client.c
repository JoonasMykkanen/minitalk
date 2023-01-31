/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:45:14 by jmykkane          #+#    #+#             */
/*   Updated: 2023/01/31 20:45:18 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	send_len(int pid, char *message)
{
	int		i;
	char	*len;

	i = 0;
	len = ft_itoa(ft_strlen(message));
	i = 10 - ft_strlen(len);
	while (--i > 0)
	{
		encode(pid, "0");
	}
	encode(pid, len);
	free(len);
}

static void	send_key(int pid)
{
	int	i;

	i = 100;
	while (--i >= 0)
	{
		kill(pid, SIGUSR1);
		usleep(1000);
	}
}

int	main(int argc, char **argv)
{
	char	*message;
	int		pid;

	if (check_input(argc, argv) == -1)
	{
		ft_printf("There was problem with input. Exiting!\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	message = ft_strdup(argv[2]);
	if (!message)
		return (0);
	send_key(pid);
	send_len(pid, message);
	encode(pid, message);
	free(message);
	return (0);
}

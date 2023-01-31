/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:45:53 by jmykkane          #+#    #+#             */
/*   Updated: 2023/01/31 20:45:57 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	send(int pid, int i, char c)
{
	if (c >> i & 1)
	{
		kill(pid, SIGUSR2);
	}
	else
	{
		kill(pid, SIGUSR1);
	}
}

void	encode(int pid, char *message)
{
	int		i;
	char	c;
	int		len;
	int		count;

	i = 8;
	count = -1;
	len = ft_strlen(message);
	while (++count < len)
	{
		c = message[count];
		while (--i >= 0)
		{
			send(pid, i, c);
			usleep(1000);
		}
		i = 8;
	}
	pid++;
}

int	check_input(int argc, char **argv)
{
	if (argc < 3 || argc > 3)
		return (-1);
	if (ft_atoi(argv[1]) == 0)
		return (-1);
	if (ft_strlen(argv[2]) == 0)
		return (-1);
	else
		return (0);
}

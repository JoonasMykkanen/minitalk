/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:46:32 by jmykkane          #+#    #+#             */
/*   Updated: 2023/01/31 20:46:34 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	translate_bytes(char *bytes)
{
	char	c;
	int		i;

	c = 0;
	i = -1;
	while (++i < 8)
	{
		if (bytes[i] == '1')
		{
			c = c | (1 << (7 - i));
		}
	}
	return (c);
}

int	calc_size(t_msg msg)
{
	int	i;
	int	sum;

	i = -1;
	sum = 0;
	while (++i < 10)
	{
		if (msg.len[i] != 0)
			sum *= 10;
		sum = sum + msg.len[i];
	}
	return (sum);
}

void	reset_server(t_msg *msg, int *g_state)
{
	ft_bzero(msg->bytes, 8);
	ft_bzero(msg->len, 10);
	free(msg->message);
	msg->index = -1;
	msg->size = 0;
	*g_state = 0;
}

void	init(t_msg *msg, int *g_state)
{
	if (*g_state == 1)
	{
		msg->i = -1;
		*g_state = 2;
		msg->index = 0;
	}
}

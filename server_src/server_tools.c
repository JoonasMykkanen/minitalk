
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
	int sum;

	i = -1;
	sum = 0;
	while (++i < 10)
	{
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
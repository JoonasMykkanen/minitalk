
#include "server.h"

int	g_state;

static void	listen_for_key(int sig)
{
	static int	count = 0;

	if (sig == 30)
		count++;
	else
		count = 0;
	if (count >= 100)
		g_state = 1;
}



static void	signal_handler(int sig)
{
	static int		i = -1;
	static t_msg	msg;

	if (g_state == 0)
		msg.index = -1;
	if (++i < 8)
	{
		if (sig == 30)
			msg.bytes[i] = '0';
		if (sig == 31)
			msg.bytes[i] = '1';
		if (i == 7)
		{
			msg.c = translate_bytes(msg.bytes);
			if (++msg.index < 10)
			{
				msg.len[msg.index] = msg.c;
				if (msg.index == 9)
				{
					msg.message = malloc(sizeof(char) * ft_atoi(msg.len) + 1);
					if (!msg.message)
						return ;
				}
			}
			else
			{
				msg.message[msg.index - 10] = msg.c;
				if ((msg.index - 10) == (ft_atoi(msg.len) - 1))
				{
					msg.message[msg.index] = '\0';
					ft_printf("%s\n", msg.message);
					free(msg.message);
					msg.index = 0;
					g_state = 0;
				}
				msg.index++;
			}
			i = -1;
		}
	}
}

int	main(void)
{
	int pid;

	g_state = 0;
	pid = getpid();
	ft_printf("pid: %d\n",pid);
	while (42)
	{
		if (g_state == 0)
		{
			signal(SIGUSR1, listen_for_key);
		}
		if (g_state == 1)
		{
			signal(SIGUSR1, signal_handler);
			signal(SIGUSR2, signal_handler);
		}
	}
	return (0);
}
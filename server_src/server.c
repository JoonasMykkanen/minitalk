
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
	{
		ft_printf("Succesfully connected to client.\n");
		g_state = 1;
	}
}

static void	signal_handler(int sig)
{
	static int		index = 0;
	static char		bytes[8];
	static int		i = -1;
	static t_msg	msg;
	char			c;

	if (g_state == 0)
	{
		msg.index = 0;
	}
	if (++i < 8)
	{
		if (sig == 30)
			bytes[i] = '0';
		if (sig == 31)
			bytes[i] = '1';
		if (i == 7)
		{
			c = translate_bytes(bytes);
			if (msg.index < 10)
			{
				msg.len[msg.index] = c;
				ft_printf("len: %c\n", msg.len[msg.index]);
				msg.index++;
				if (msg.index == 9)
					msg.message = malloc(sizeof(char) * ft_atoi(msg.len) + 1);
			}
			else
			{
				msg.message[index] = c;
				index++;
				if (index == ft_atoi(msg.len))
				{
					msg.message[index] = '\0';
					ft_printf("%s\n", msg.message);
					free(msg.message);
					msg.index = 0;
					index = 0;
				}
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
		if (g_state == 2)
		{
		
		}
	}
	return (0);
}
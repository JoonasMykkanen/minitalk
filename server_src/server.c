
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

static void	print_message(t_msg *msg, int *g_state)
{
	msg->message[msg->index - 10] = msg->c;
	msg->index++;
	msg->message[msg->index - 10] = '\0';
	ft_printf("%s\n", msg->message);
	reset_server(msg, g_state);
}

static void save_signal(t_msg *msg, int sig)
{
	msg->i++;
	if (sig == 30)
		msg->bytes[msg->i] = '0';
	if (sig == 31)
		msg->bytes[msg->i] = '1';
}

static void	signal_handler(int sig)
{
	static t_msg	msg;

	init(&msg, g_state);
	save_signal(&msg, sig);
	if (msg.i == 7)
	{
		msg.c = translate_bytes(msg.bytes);
		if (++msg.index < 10)
		{
			msg.len[msg.index] = ft_atoi(&msg.c);
			if (msg.index == 9)
			{
				msg.message = malloc(sizeof(char) * calc_size(msg) + 1);
				if (!msg.message)
					return ;
			}
		}
		else
		{
			msg.message[msg.index - 10] = msg.c;
			if ((msg.index - 10) == (calc_size(msg) - 1))
				print_message(&msg, &g_state);
		}
		msg.i = -1;
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
		if (g_state == 1 || g_state == 2)
		{
			signal(SIGUSR1, signal_handler);
			signal(SIGUSR2, signal_handler);
		}
	}
	return (0);
}
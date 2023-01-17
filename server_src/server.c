
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
	static int	len = -1;
	static char	bytes[8];
	char		c;

	if (++len < 8)
	{
		if (sig == 30)
			bytes[len] = '0';
		if (sig == 31)
			bytes[len] = '1';
		if (len == 7)
		{
			c = translate_bytes(bytes);
			write(1, &c, 1);
			len = -1;
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
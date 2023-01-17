
#include "client.h"

void	send_key(int pid)
{
	int i;

	i = 100;
	while (--i >= 0)
	{
		kill(pid, SIGUSR1);
		usleep(1000);
	}
}


int	main(int argc, char **argv)
{
	int		pid;
	char	*message;

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
	encode(pid, message);
	free(message);
	return (0);
}
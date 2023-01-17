

#ifndef CLIENT_H
# define CLIENT_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <signal.h>

void	send(int pid, int i, char c);
void	encode(int pid, char *message);
int		check_input(int argc, char **argv);

#endif


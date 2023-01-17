

#ifndef SERVER_H
# define SERVER_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

typedef struct s_message
{
	char	*message;
	char	len[10];
	int		index;
}			t_msg;

char	translate_bytes(char *bytes);

#endif
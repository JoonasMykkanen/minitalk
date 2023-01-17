
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
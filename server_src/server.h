/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 11:09:44 by jmykkane          #+#    #+#             */
/*   Updated: 2023/01/02 11:09:51 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

typedef struct s_message
{
	char	*message;
	char	bytes[8];
	int		len[10];
	int		index;
	int		size;
	char	c;
	int		i;
}			t_msg;

void	reset_server(t_msg *msg, int *g_state);
void	init(t_msg *msg, int *g_state);
char	translate_bytes(char *bytes);
int		calc_size(t_msg msg);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:45:36 by jmykkane          #+#    #+#             */
/*   Updated: 2023/01/31 20:45:39 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <signal.h>

void	send(int pid, int i, char c);
void	encode(int pid, char *message);
int		check_input(int argc, char **argv);

#endif

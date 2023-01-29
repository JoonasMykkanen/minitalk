SERVER = server

CLIENT = client

LIBFT = libft.a

SRC_SERVER = server_src/server.c server_src/server_tools.c

SRC_CLIENT = client_src/client.c client_src/client_tools.c

SERVER_INCLUDES = -Iserver_src -Ilibft -L. -lft

CLIENT_INCLUDES = -Iclient_src -Ilibft -L. -lft

FLAGS = -Wall -Werror -Wextra

all: $(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT):
	cd libft && $(MAKE)
	cp libft/libft.a libft.a
	rm -f libft/libft.a

$(SERVER):
	cc -o $(SERVER) $(SRC_SERVER) $(FLAGS) $(SERVER_INCLUDES) 

$(CLIENT):
	cc -g -o $(CLIENT) $(SRC_CLIENT) $(FLAGS) $(CLIENT_INCLUDES) 
	
clean:
	cd libft && $(MAKE) clean
	rm -f libft.a

fclean:
	$(MAKE) clean
	rm -f server
	rm -f client

re:
	$(MAKE) fclean
	$(MAKE) all

test: fclean
	cd libft && $(MAKE)
	cp libft/libft.a libft.a
	rm -f libft/libft.a
	cc -o $(SERVER) $(SRC_SERVER) $(SERVER_INCLUDES) -L. -lft
	cc -o $(CLIENT) $(SRC_CLIENT) $(CLIENT_INCLUDES) -L. -lft
	$(MAKE) fclean
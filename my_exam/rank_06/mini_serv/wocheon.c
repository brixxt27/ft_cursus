#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>

#define BUF_SIZE 42 * 4092

typedef struct client {
	int id;
	char msg[110000];
}	t_client;

int error_exit(char *str) {
	write(2, str, strlen(str));
	exit(1);
}

t_client client_arr[1024];
int max, next_id;
fd_set fd_active, fd_read, fd_write;
char read_buf[BUF_SIZE], write_buf[BUF_SIZE];

void send_all(int es) {
	for (int i = 0; i <= max; i++) {
		if(FD_ISSET(i, &fd_write) && i != es)
      send(i, write_buf, strlen(write_buf), 0);
	}
}

int main(int argc, char **argv) {
	if (argc != 2)
		error_exit("Wrong number of arguments\n");


	bzero(&client_arr, sizeof(client_arr));
	FD_ZERO(&fd_active);

	int server_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (server_socket < 0)
		error_exit("Fatal error\n");

	max = server_socket;
	FD_SET(server_socket, &fd_active);

	struct sockaddr_in servaddr;
	socklen_t addr_len = sizeof(servaddr);
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(argv[1]));

	if (bind(server_socket, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
		error_exit("Fatal error\n");
	if (listen(server_socket, 128) < 0)
		error_exit("Fatal error\n");

	while (1) {
		fd_read = fd_write = fd_active;

		if (select(max + 1, &fd_read, &fd_write, NULL, NULL) < 0)
			continue ;

		for (int s = 0; s <= max; s++) {
			if (FD_ISSET(s, &fd_read) && s == server_socket) {
				int client_socket = accept(server_socket, (struct sockaddr *)&servaddr, &addr_len);
				if (client_socket < 0)
					continue ;
				max = client_socket > max ? client_socket : max;
				client_arr[client_socket].id = next_id++;
				FD_SET(client_socket, &fd_active);
				sprintf(write_buf, "server: client %d just arrived\n", client_arr[client_socket].id);
				send_all(client_socket);
				break ;
			}
			if (FD_ISSET(s, &fd_read) && s != server_socket) {
				int res = recv(s, read_buf, BUF_SIZE, 0);
				if (res <= 0) {
					sprintf(write_buf, "server: client %d just left\n", client_arr[s].id);
					send_all(s);
					FD_CLR(s, &fd_active);
					close(s);
					break ;
				} else {
					for (int i = 0, j = strlen(client_arr[s].msg); i < res; i++, j++) {
            client_arr[s].msg[j] = read_buf[i];
            if (client_arr[s].msg[j] == '\n') {
              client_arr[s].msg[j] = '\0';
              sprintf(write_buf, "client %d: %s\n", client_arr[s].id, client_arr[s].msg);
              send_all(s);
							bzero(&client_arr[s].msg, strlen(client_arr[s].msg));
              j = -1;
            }
					}
          break;
				}
			}
		}
	}
}
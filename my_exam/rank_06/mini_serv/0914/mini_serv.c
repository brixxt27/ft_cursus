#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

void putstrFd(int fd, char* s) {
	write(fd, s, strlen(s));
}

void argErr(void) {
	putstrFd(2, "Wrong number of arguments\n");
	exit(1);
}

void sysErr(void) {
	putstrFd(2, "Fatal error\n");
	exit(1);
}

void allocErr(void) {
	putstrFd(2, "Fatal error\n");
	exit(1);
}

/**
 * Entire variables
*/
typedef struct s_client {
	int id;
} Client;
int nextId = 0;
int maxFd = 0;
int servfd;
const int kBuffSize = 42424;
char buff[kBuffSize];
Client client[1024];
fd_set readfds, writefds, originfds;

/**
 * main loginc
*/

void sendAll(int exception) {
	for (int i = 0; i <= maxFd; i++) {
		if (FD_ISSET(i, &writefds)) {
			if (exception != i) {
				send(i, buff, kBuffSize, 0);
			}
		}
	}
}

void initServer(int port) {
	struct sockaddr_in servaddr; 

	// socket create and verification 
	servfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (servfd == -1) { 
		sysErr();
	} 
	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(port); 
  
	// Binding newly created socket to given IP and verification 
	if ((bind(servfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) < 0) { 
		sysErr();
	} 
	if (listen(servfd, 128) < 0) {
		sysErr();
	}
	maxFd = servfd;
	FD_ZERO(&originfds);
	FD_SET(servfd, &originfds);
}

void	initClient(void) {
	int connfd;
	socklen_t len;
	struct sockaddr_in  cli;

	len = sizeof(cli);
	connfd = accept(servfd, (struct sockaddr *)&cli, &len);
	if (connfd < 0) { 
		sysErr();
	} 
	FD_SET(connfd, &originfds);
	if (maxFd < connfd) {
		maxFd = connfd;
	}
	client[connfd].id = nextId;
	nextId++;
	sprintf(buff, "server: client %d just arrived\n", client[connfd].id);
	sendAll(connfd);
	memset(buff, 0, strlen("server: client %d just arrived\n"));
}

void receiveFromClient(int fd) {
	int ret = recv(fd, buff, kBuffSize, 0);

	if (ret == 0) {
		sprintf(buff, "server: client %d just left\n", client[fd].id);
		sendAll(fd);
		FD_CLR(fd, &originfds);
		close(fd);
		memset(buff, 0, strlen("server: client %d just left\n"));
	}
	else {

	}

}

int main(int argc, char** argv)
{
	int port;

	if (argc != 2) 
		argErr();
	port = atoi(argv[1]);
	initServer(port);

	while (1) {
		readfds = originfds;
		writefds = originfds;
		if (select(maxFd + 1, &readfds, &writefds, NULL, NULL) <= 0)
			continue;
		for (int currFd = 0; currFd <= maxFd; currFd++) {
			if (FD_ISSET(currFd, &readfds)) { // read event
				if (currFd == servfd) {
					initClient();
				}
				else {
					receiveFromClient(currFd);
				}
			}
		}
	}
}
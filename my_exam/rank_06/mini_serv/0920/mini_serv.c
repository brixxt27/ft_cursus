#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>

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

int port;
int servFd;
int connFd;
int nextId;
int maxFd;
const int buffSize = 4096;

char writeBuff[buffSize];
char readBuff[buffSize];
char tempBuff[buffSize];

Client client[1024];
fd_set originFd, readCopy, writeCopy;

void initServ(void) {
	struct sockaddr_in servaddr;

	// socket create and verification 
	servFd = socket(AF_INET, SOCK_STREAM, 0); 
	if (servFd == -1) { 
		sysErr();
	}  
	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(port); 
  
	// Binding newly created socket to given IP and verification 
	if ((bind(servFd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) { 
		sysErr();
	} 

	if (listen(servFd, 128) != 0) {
		sysErr();
	}
	maxFd = servFd;
	FD_ZERO(&originFd);
	FD_SET(servFd, &originFd);
}

void sendAll(int exception) {
	for (int fd = 0; fd <= maxFd; fd++) {
		if (FD_ISSET(fd, &writeCopy)) {
			if (fd != exception) {
				send(fd, writeBuff, strlen(writeBuff), 0);
			}
		}
	}
}

void initClient(void) {
	struct sockaddr_in cli; 
	socklen_t len;

	len = sizeof(cli);
	connFd = accept(servFd, (struct sockaddr *)&cli, &len);
	if (connFd < 0) { 
    sysErr();
  }

	client[connFd].id = nextId++;
	if (maxFd < connFd) {
		maxFd = connFd;
	}
	FD_SET(connFd, &originFd);

	sprintf(writeBuff, "server: client %d just arrived\n", client[connFd].id);
	sendAll(connFd);
}

void recvMsgToClient(int fd) {
	int ret;

	ret = recv(fd, readBuff, buffSize - 1, 0);
	if (ret == 0) {
		// disconnect client
		sprintf(writeBuff, "server: client %d just left\n", client[fd].id);
		sendAll(fd);

		FD_CLR(fd, &originFd);
		close(fd);
		if (maxFd == fd) {
			maxFd--;
		}
	}
	else {
		// send messages
		for (int i = 0, j = 0; i < ret; i++, j++) {
			tempBuff[j] = readBuff[i];
			if (tempBuff[j] == '\n') {
				tempBuff[j] = '\0';
				sprintf(writeBuff, "client %d: %s\n", client[fd].id, tempBuff);
				sendAll(fd);
				j = -1;
			}
		}
	}
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		argErr();
	}
	port = atoi(argv[1]);
	initServ();

	while (1) {
		writeCopy = originFd;
		readCopy = originFd;

		select(maxFd + 1, &readCopy, &writeCopy, NULL, NULL);

		for (int fd = 0; fd < maxFd + 1; fd++) {
			if (FD_ISSET(fd, &readCopy)) {
				if (fd == servFd) {
					initClient();
				}
				else {
					recvMsgToClient(fd);
				}
			}
		}
	}
}
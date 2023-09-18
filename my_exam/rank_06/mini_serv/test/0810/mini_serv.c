#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>

//test
// #include <stdio.h>

static void printStr(const int fd, const char* str) {
	write(fd, str, strlen(str));
}

static void printArgErr(void) {
	const char* str = "Wrong number of arguments\n";

	printStr(2, str);
	exit(1);
}

/**
 * @brief 
 * Before start
 */
static void printSysCallErr(void) {
	const char* str = "Fatal error\n";

	printStr(2, str);
	exit(1);
}

static void printAllocErr(void) {
	const char* str = "Fatal error\n";

	printStr(2, str);
	exit(1);
}

typedef struct Client {
	int id;
	char msg[10000];
} Client;

/*
variable
*/
int servSock;
Client clinet[2000];
/*
variable
*/

void initServer(const int port) {
	int servSock, connfd;
	struct sockaddr_in servaddr, cli; 
	socklen_t len;

	// socket create and verification 
	servSock = socket(AF_INET, SOCK_STREAM, 0); 
	if (servSock == -1) { 
		printSysCallErr();
	} 
	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(port); 
  
	// Binding newly created socket to given IP and verification 
	if ((bind(servSock, (const struct sockaddr *)&servaddr, sizeof(servaddr))) < 0) { 
		printSysCallErr();
	} 
	if (listen(servSock, 128) < 0) {
		printSysCallErr();
	}
}

void runServ(void) {
	struct sockaddr_in cli; 
	socklen_t len;
	int connfd;

	while (1) {
		len = sizeof(cli);
		connfd = accept(servSock, (struct sockaddr *)&cli, &len);
		if (connfd < 0) { 
			printSysCallErr();
		} 
	}
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		printArgErr();
	}
	const int port = atoi(argv[1]);

	initServer(port);
	runServ();
}
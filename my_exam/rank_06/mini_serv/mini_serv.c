#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>

static void printStr(const int fd, const char* str) {
	write(fd, str, strlen(str));
}

static void printArgErr(void) {
	const char* str = "Wrong number of arguments\n";

	printStr(2, str);
}

static void printSysCallErrBeforeStart(void) {
	const char* str = "Fatal error\n";

	printStr(2, str);
}

static void printAllocErr(void) {
	const char* str = "Fatal error\n";

	printStr(2, str);
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		printArgErr();
		exit(1);
	}

	const int port = atoi(argv[1]);
}
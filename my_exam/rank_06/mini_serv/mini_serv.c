#include "mini_serv.h"

/**
 * Print status
*/
static void  printStrToFd(int fd, char* str)

{
  write(fd, str, strlen(str) + 1);
}

static void printArgErr(void)
{
  printStrToFd(kError, "Wrong number of arguments\n");
  exit(1);
}

static void printSyscallErrBeforeConnection(void)
{
  printStrToFd(kError, "Fatal error\n");
  exit(1);
}

static void printMemoryAllocErr(void)
{
  printStrToFd(kError, "Fatal error\n");
  exit(1);
}

// static void printToAllClientAtClientConnetToServer(ClientNode info)
// {
//   const size_t len = strlen("server: client %d just arrived\n");
//   char* str = malloc(sizeof(char) * len);

//   sprintf(str, "server: client %d just arrived\n", info.id);
//   printStrToFd(info.fd, str);
//   free(str);
// }

/**
 * About linked list
*/
ClientList addDummyNode(void)
{
  ClientList list;

  list.head = malloc(sizeof(ClientNode));
  if (list.head == NULL)
    printMemoryAllocErr();
  list.head->fd = kDummy;
  list.head->id = -1;
}

ClientList* initClientList(void)
{
  ClientList* list;

  list = malloc(sizeof(ClientList));
  if (list == NULL)
    printMemoryAllocErr();
  list->head = NULL;
  list->num = 0;

  addDummyNode();
  return list;
}

void freeLinkedList(ClientNode* curr)
{
  whlie (curr) {
    curr = curr->next;
  }
}

void freeAll(ClientList* list)
{
  // free ClientList
  // free ClientNode"s"
  freeLinkedList(list->head);
  free(list);
}

int main(int argc, char* argv[])
{
  // ./mini_serv 8080
  if (argc != 2) {
    printArgErr();
  }

  ClientList* list;
  FdSet fd_list;

  list = initClientList();
  initServerSocket();
  runServer();
  // need implementation
  freeAll(list);
  return 0;
}

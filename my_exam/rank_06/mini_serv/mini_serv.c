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
ClientNode* addDummyNode(ClientNode* head)
{
  head = malloc(sizeof(ClientNode));
  if (head == NULL)
    printMemoryAllocErr();
  head->fd = kDummyFd;
  head->id = -1;
  return head;
}

ClientList* initClientList(void)
{
  ClientList* list;

  list = malloc(sizeof(ClientList));
  if (list == NULL)
    printMemoryAllocErr();
  list->num = 0;
  list->head = addDummyNode(list->head);
  list->tail = list->head;
  return list;
}

void addClient(ClientList* list, int fd)
{
  if (list == NULL)
    return;

  ClientNode* tail = list->tail;

  tail->next = malloc(sizeof(ClientNode));
  if (tail->next == NULL)
    printMemoryAllocErr();
  list->num++;
  tail->next->fd = fd;
  tail->next->id = tail->id + 1;
  tail->next->next = NULL;
  list->tail = tail->next;
}

/*
1
next -> 2
        next -> 3
                next -> NULL
*/

void deleteClient(ClientList* list, int fd)
{
  if (list == NULL)
    return;
  
  ClientNode* curr = list->head;
  ClientNode* prev = curr;

  while (curr) {
    if (curr->fd == fd) {
      prev->next = curr->next;
      list->num--;
      if (curr == list->tail)
        list->tail = prev;
      free(curr);
      curr = NULL;
      break; // Exist not duplicated fd
    }
    prev = curr;
    curr = curr->next;
  }
}

void printList(ClientList* list)
{
  if (list == NULL)
    printf("List is empty");

  ClientNode* curr = list->head;
  int i = 0;

  printf("Num is %d\n", list->num);
  printf("************************\n");
  while (curr) {
    printf("@@'%d'th Client@@\n", i);
    printf("fd is %d\n", curr->fd);
    printf("id is %d\n", curr->id);
    curr = curr->next;
    i++;
    printf("************************\n");
  }
  printf("\n");
}

void freeLinkedList(ClientNode* curr)
{
  if (curr == NULL)
    return;
  ClientNode* next;

  while (curr) {
    next = curr->next;
    free(curr);
    curr = next;
  }
}

void freeAll(ClientList* list)
{
  // free ClientNode's'
  // free ClientList
  freeLinkedList(list->head);
  free(list);
}

void checkLeak(void)
{
  system("leaks a.out");
}

int main(int argc, char* argv[])
{
  // atexit(checkLeak);
  int i = 0; // delete this

  // ./mini_serv 8080
  if (argc != 2) {
    printArgErr();
  }

  ClientList* list;
  FdSet fd_list;

  list = initClientList();
  addClient(list, i++);
  addClient(list, i++);
  addClient(list, i++);
  printList(list);

  addClient(list, i++);
  deleteClient(list, 2);
  printList(list);

  deleteClient(list, 1);
  deleteClient(list, 3);
  printList(list);
  deleteClient(list, 0);
  printList(list);

  // initServerSocket();
  // runServer();
  freeAll(list);
  return 0;
}

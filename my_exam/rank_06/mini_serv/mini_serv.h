#ifndef MINI_SERV_H
#define MINI_SERV_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/select.h>


/**
 * structure and enum
 */

enum e_stdio {
  kIn = 0,
  kOut,
  kError
};

enum e_list {
  kDummy = -2,
  kNode = -1
};

typedef struct sClient {
  int fd;
  int id;
  struct sClient* next;
} ClientNode;

typedef struct sClientList {
  ClientNode* head;
  int num;
} ClientList;

typedef struct sFdSet {
  fd_set read_fds;
  fd_set write_fds;
} FdSet;

#endif
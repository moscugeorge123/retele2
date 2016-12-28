#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "class/class.h"


/* Portul folosit */
#define PORT 2024

/* codul de eroare returnat de anumite apeluri */
extern int errno;

int main()
{
  /* Pornirea serverului pana la comanda bind */
  Server* server = new Server(PORT);

  return 0;
} 
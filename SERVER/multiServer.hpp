#ifndef MULTISERVER
#define MULTISERVER
#define MAX 1025

#include "user.hpp"

int server(int argc , char *argv[]);
void direct(int sd,char buffer[MAX]);

#endif

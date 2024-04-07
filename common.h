#pragma once
#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

#define BUFSIZE 1024
#define PORT 8080
#define BACKLOG 10
//char username[8];
//#define USERNAME username

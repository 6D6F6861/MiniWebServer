#ifndef __SERVER_HPP_
#define __SERVER_HPP_

#include<iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <string>
#include <fcntl.h>
#include <fstream>

struct addrinfo *getinfostruct(char *hostname, char *port);
int get_socketId(struct addrinfo *hints);
std::string read_request(int sockId);

#endif
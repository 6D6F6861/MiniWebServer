#ifndef __REQUEST_HPP__
#define __REQUEST_HPP__

#include<iostream>
#include<string>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <fstream>
#include <map>

using namespace std;

class request
{
    private:
        string request_;
    public:
        void    parsingRequest(void);
        void    read_request(int sockId);
        void    print_request(void);
};

#endif
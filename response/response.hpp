#ifndef __RESPONSE_HPP__
#define __RESPONSE_HPP__

#include<map>
#include<string>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fstream>
#include <sys/socket.h>

using namespace std;

class   response
{
    private:
        string              response_;
        string              target;
    public:
        bool                found;
        void    check_request(void);
        void    generate_response(void);
        void    sendResponse(int sockId);
};

#endif
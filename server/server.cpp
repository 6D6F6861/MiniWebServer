#include "server.hpp"

struct addrinfo *getinfostruct(char *hostname, char *port)
{
    struct addrinfo hints, *res;
    int err;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    if ((err = getaddrinfo(hostname, port, &hints, &res)) != 0)
    {
        std::cout << "getaddrinfo: " << gai_strerror(err) << std::endl;
        exit(1);
    }
    return (res);
}

int get_socketId(struct addrinfo *hints)
{
    struct addrinfo *p;
    int sockId;

    for (p = hints; p != NULL; p = p->ai_next)
    {
        sockId = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockId == -1)
            continue;
        if (bind(sockId, p->ai_addr, p->ai_addrlen) == 0)
            break ;
        close(sockId);
    }

    if (p == NULL)
    {
        std::cout << "Error: " << strerror(errno) << std::endl;
        exit(1);
    }
    return (sockId);
}

std::string read_request(int sockId)
{
    char        buff[300];
    ssize_t     readBuff;

    readBuff = recv(sockId, buff, 300, 0);
    if (readBuff == -1)
    {
        std::cout << "read Error: " << strerror(errno) << std::endl;
        exit(1);
    }
    if (readBuff == 0)
        return std::string();
    return (std::string (buff));
}
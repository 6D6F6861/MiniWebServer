#include "./server/server.hpp"
#include "./request/request.hpp"
#include "./response/response.hpp"

int main(int ac, char *av[])
{
    struct addrinfo *hints, *res;
    struct sockaddr_storage coming;
    int sockbind, comingSock;
    socklen_t addrlen;
    char buff[30000];

    if (ac != 2)
    {
        std::cout << "Usage: ./program <port>" << std::endl;
        exit(1);
    }
    hints = getinfostruct("127.0.0.1", av[1]);
    sockbind = get_socketId(hints);
    if (listen(sockbind, SOMAXCONN) == -1)
    {
        std::cout << "listen Error: " << strerror(errno) << std::endl;
        exit(2);
    }
    addrlen = sizeof(coming);
    response respo;
    request req;
    while (1)
    {
        if ((comingSock = accept(sockbind, (struct sockaddr *) &coming, &addrlen)) == -1)
        {
            std::cout << "accept Error: " << strerror(errno) << std::endl;
            exit(1);
        }
        // req.read_request(comingSock);
        respo.found = false;
        req.read_request(comingSock);
        // req.print_request();
        respo.generate_response();
        respo.sendResponse(comingSock);
        close(comingSock);
        break;
    }
    return (0);
}
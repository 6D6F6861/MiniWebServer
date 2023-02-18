#include "request.hpp"

void    request::read_request(int sockId)
{
    char buff[30000];

    request_.clear();
    request_ = "";
    read(sockId, buff, 30000);
    request_ += string(buff);
}

void    request::print_request(void)
{
    cout << request_ << endl;
}

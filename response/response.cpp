#include "response.hpp"

void    response::check_request(void)
{
    ifstream file(target.c_str());
    if (file.good())
        found = true;
    else
        found = false;
}

void    response::generate_response(void)
{
    response_ = "";
    if (found)
    {
        response_ += "HTTP/1.1 200 OK\r\n";
        response_ += "Content-Type: text/html; charset=utf-8\r\n\n";
        response_ += "<!DOCTYPE html><html lang=\"en\"><head> <meta charset=\"UTF-8\"> <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\"> <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"> <title>Sample HTML Code - NewsLetter Form</title></head><body> <main> <!-- intro section --> <section class=\"intro\"> <h1 class=\"title\">Black Friday Deals</h1> <p>Get up to 50% off on all our products and services. Hurry up, the offer ends in 24 hours.</p> </section> <!-- sign-up section --> <section class=\"sign-up\"> <p class=\"sign-up-para\">Sign up for our newsletter and get 10% off your first purchase</p> <!-- the form itself --> <form class=\"sign-up-form\"> <div class=\"form-input\"> <input type=\"text\" name=\"first-name\" id=\"first-name\" placeholder=\"First Name\" required> <span>!</span> <p class=\"warning\">First name cannot be empty</p> </div> <div class=\"form-input\"> <input type=\"text\" name=\"last-name\" id=\"last-name\" placeholder=\"Last Name\" required> <span>!</span> <p class=\"warning\">Last name cannot be empty</p> </div> <div class=\"form-input\"> <input type=\"email\" name=\"email\" id=\"email\" placeholder=\"Email Address\" required> <span>!</span> <p class=\"warning\">Looks like this is not an email</p> </div> <div class=\"form-input\"> <input type=\"Password\" name=\"Password\" id=\"Password\" placeholder=\"Password\" required> <span>!</span> <p class=\"warning\">Password cannot be empty</p> </div> <input class=\"submit-btn\" type=\"submit\" value=\"Claim your off\"> <p clas\"form-te\">By clicking the button, you are agreeing to our <span>Terms and Services</span> </p> </form> </section> </main></body></html>";
    }
    else
    {
        response_ += "HTTP/1.1 404 Not Found";
        response_ += "Content-Type: text/html; charset=utf-8\r\n\n";
        response_ += "<!DOCTYPE html><html lang=\"en\"><head> <meta charset=\"UTF-8\"> <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\"> <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"> <title>Error 404 page</title></head><body> <div class=\"container\"> <h1>404</h1> <h2>Page not found</h2> <p>The page you are looking for does not exist.</p> <p><a href=\"#\">Visit Homepage</a></p> </div></body></html>\n";
    }
}


void    response::sendResponse(int sockId)
{
    char    *buff;

    buff = (char *)response_.c_str();
    send(sockId,(const char *)buff,strlen(buff), 0);
}

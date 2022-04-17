#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED

#include <string>

struct Admin {
    std::string username;
    size_t password;
    Admin();
    Admin(std::string paramUsername, std::string paramPassword);
};

#endif

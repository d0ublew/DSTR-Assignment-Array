#include <string>
#include <vector>

#include "admin.h"

Admin::Admin()
{
    username = "";
    password = "";
}

Admin::Admin(std::string paramUsername, std::string paramPassword)
{
    username = paramUsername;
    password = paramPassword;
}

Admin *getAdminByUsername(std::vector<Admin> &adminV, std::string username)
{
    std::vector<Admin>::iterator it;

    for (it = adminV.begin(); it != adminV.end(); it++)
    {
        Admin s = *it;
        if (s.username == username)
        {
            /**
             * Dereference to get the object in the heap and then get the
             * address
             */
            return &(*it);
        }
    }
    return nullptr;
}

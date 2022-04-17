#include <string>
#include "admin.h"

Admin::Admin() {
    username = "";
    password = 0;
}

Admin::Admin(std::string paramUsername, std::string paramPassword) {
    std::hash<std::string> h;
    username = paramUsername;
    password = h(paramPassword);
}

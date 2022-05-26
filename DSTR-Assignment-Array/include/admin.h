#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED

#include <string>
#include <vector>

struct Admin {
  std::string username;
  std::string password;
  Admin();
  Admin(std::string paramUsername, std::string paramPassword);
};

Admin *getAdminByUsername(std::vector<Admin> &adminV, std::string username);

#endif

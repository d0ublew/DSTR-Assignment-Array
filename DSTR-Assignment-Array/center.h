#ifndef CENTER_H_INCLUDED
#define CENTER_H_INCLUDED

#include <string>
#include <vector>

struct Center {
    std::string name;
    std::string ID;
};

Center* getCenterByID(std::vector<Center> &, std::string ID);

#endif

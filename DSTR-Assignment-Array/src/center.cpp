#include <string>
#include <vector>

#include "center.h"

Center *getCenterByID(std::vector<Center> &centerV, std::string ID)
{
    std::vector<Center>::iterator it;

    for (it = centerV.begin(); it != centerV.end(); it++)
    {
        Center c = *it;
        if (c.ID == ID)
        {
            return &(*it);
        }
    }
    return nullptr;
}

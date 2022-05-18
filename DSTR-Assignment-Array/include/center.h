#ifndef CENTER_H_INCLUDED
#define CENTER_H_INCLUDED

#include <string>
#include <vector>

struct Center {
  std::string ID;
  std::string name;
};

/**
 * @brief Function to retrieve pointer to Center object with matching ID
 *
 * @param centerV specifies the array of Center object to be checked
 * @param ID specifies the string to be matched
 *
 * @return nullptr if not found, else pointer to the object
 */
Center *getCenterByID(std::vector<Center> &centerV, std::string ID);

#endif

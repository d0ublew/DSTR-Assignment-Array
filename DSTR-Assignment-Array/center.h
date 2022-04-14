#ifndef CENTER_H_INCLUDED
#define CENTER_H_INCLUDED

#include <string>

struct Center {
    std::string name;
    std::string ID;
};

struct CenterArr {
    Center* arr;
    size_t size;
    CenterArr();
    CenterArr(size_t);
    ~CenterArr();
    void Print();
    Center* getCenterByID(std::string ID);
};

#endif

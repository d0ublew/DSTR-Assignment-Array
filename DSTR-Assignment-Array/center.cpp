#include <iostream>

#include "center.h"

CenterArr::CenterArr() {
    arr = nullptr;
    size = 0;
}

CenterArr::CenterArr(size_t paramSize) {
    arr = new Center[paramSize];
    size = paramSize;
}

CenterArr::~CenterArr() {
    delete[] arr;
}

Center* CenterArr::getCenterByID(std::string ID) {
    for (size_t i = 0; i < size; i++) {
        if (arr[i].ID == ID) {
            return &arr[i];
        }
    }
    return nullptr;
}

void CenterArr::Print() {
    for (size_t i = 0; i < size; i++) {
        std::cout << arr[i].ID << ' ' << arr[i].name << '\n';
    }
}
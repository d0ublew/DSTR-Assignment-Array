#include <fstream>
#include <string>
#include <vector>
#include <iostream>

#include "date.h"
#include "tutor.h"
#include "subject.h"
#include "center.h"
#include "file2struct.h"

void fileToTutor(std::vector<Tutor> &tutorV, std::string filename) {
    std::fstream fileHandler(filename, std::ios::in | std::ios::binary);
    size_t size = 0;
    /*
     * Get the expected size of the vector
     */
    fileHandler.read(reinterpret_cast<char*>(&size), sizeof(size_t));
    /* std::cout << size << '\n'; */
    tutorV.resize(size);
    fileHandler.read(reinterpret_cast<char*>(&tutorV[0]), sizeof(Tutor)*size);
    std::cout << tutorV.at(0).ID << '\n';
    fileHandler.close();
}

void tutorToFile(std::vector<Tutor> &tutorV, std::string filename) {
    std::fstream fileHandler(filename, std::ios::out | std::ios::binary);
    size_t size = tutorV.size();
    /*
     * First write the size of the vector which will then be used to reserve
     * another vector to get back the data
     */
    fileHandler.write(reinterpret_cast<char*>(&size), sizeof(size_t));
    std::cout << sizeof(size_t) << '\n';
    std::cout << sizeof(Tutor)*size << '\n';
    fileHandler.write(reinterpret_cast<char*>(&tutorV[0]), sizeof(Tutor)*size);
    fileHandler.close();
}

std::vector<std::string>* splitString(std::string str, std::string delim) {
    std::vector<std::string>* data = new std::vector<std::string>;

    size_t start = 0;
    size_t end = str.find(delim);
    while (end != std::string::npos) {
        data->push_back(str.substr(start, end-start));
        start = end + delim.length();
        end = str.find(delim, start);
    }
    data->push_back(str.substr(start));

    return data;
}

#include <fstream>
#include <string>

#include "date.h"
#include "tutor.h"
#include "subject.h"
#include "center.h"
#include "file2struct.h"

size_t getLineNumber(std::string filename) {
    /*
     * Return the total line number of a file
     */

    std::fstream fileHandler;
    std::string line = "";

    fileHandler.open(filename, std::ios::in);
    size_t countLine = 0;
    while (!getline(fileHandler, line).eof()) {
        countLine++;
    }
    return countLine;
}

std::string* splitString(std::string str, std::string delim) {
    size_t numOfField = countField(str, delim);
    std::string* arr = new std::string[numOfField];
    size_t idx = 0;

    size_t start = 0;
    size_t end = str.find(delim);
    while (end != std::string::npos) {
        arr[idx++] = str.substr(start, end-start);
        start = end + delim.length();
        end = str.find(delim, start);
    }
    arr[idx] = str.substr(start);
    return arr;
}

size_t countField(std::string str, std::string delim) {
    size_t count = 0;
    size_t start = 0;
    size_t end = str.find(delim);
    while (end != std::string::npos) {
        count++;
        start = end + delim.length();
        end = str.find(delim, start);
    }
    count++;
    return count;
}

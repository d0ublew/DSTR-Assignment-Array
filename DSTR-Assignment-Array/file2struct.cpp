#include <fstream>
#include <string>
#include <vector>
#include <iostream>

#include "date.h"
#include "tutor.h"
#include "subject.h"
#include "center.h"
#include "file2struct.h"

std::vector<Tutor> fileToTutor(std::string filename) {
    std::vector<Tutor> tutorV;
    std::fstream fileHandler(filename, std::ios::in);
    std::string line = "";
    std::string delim = "|";

    while (!getline(fileHandler, line).eof()) {
        std::vector<std::string> data = splitString(line, delim);
        Tutor t;
        t.ID = data.at(0);
        t.name = data.at(1);
        t.payRate = std::stof(data.at(2));
        t.rating = std::stof(data.at(3));
        t.phone = data.at(4);
        t.joinDate = Date(data.at(5));
        t.terminateDate = Date(data.at(6));
        t.center = getCenterByID(_CENTER, data.at(7));
        t.subject = getSubjectByID(_SUBJECT, data.at(8));
        tutorV.push_back(t);
    }
    fileHandler.close();
    return tutorV;
}

std::vector<Subject> fileToSubject(std::string filename) {
    std::vector<Subject> subjectV;
    std::fstream fileHandler(filename, std::ios::in);
    std::string line = "";
    std::string delim = "|";

    while (!getline(fileHandler, line).eof()) {
        std::vector<std::string> data = splitString(line, delim);
        Subject s;
        s.ID = data.at(0);
        s.name = data.at(1);
        subjectV.push_back(s);
    }
    fileHandler.close();
    return subjectV;
}

std::vector<Center> fileToCenter(std::string filename) {
    std::vector<Center> centerV;
    std::fstream fileHandler(filename, std::ios::in);
    std::string line = "";
    std::string delim = "|";

    while (!getline(fileHandler, line).eof()) {
        std::vector<std::string> data = splitString(line, delim);
        Center c;
        c.ID = data.at(0);
        c.name = data.at(1);
        centerV.push_back(c);
    }
    fileHandler.close();
    return centerV;
}

std::vector<std::string> splitString(std::string str, std::string delim) {
    std::vector<std::string> data;
    size_t start = 0;
    size_t end = str.find(delim);
    while (end != std::string::npos) {
        data.push_back(str.substr(start, end-start));
        start = end + delim.length();
        end = str.find(delim, start);
    }
    data.push_back(str.substr(start));
    return data;
}

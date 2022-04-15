#include <fstream>
#include <string>
#include <vector>
#include <iostream>

#include "date.h"
#include "tutor.h"
#include "subject.h"
#include "center.h"
#include "file2struct.h"

void fileToTutor(std::vector<Tutor> &tutorV, std::vector<Subject> &subjectV,
        std::vector<Center> &centerV, std::string filename) {
    std::fstream fileHandler(filename, std::ios::in);
    std::string line = "";
    std::string delim = "|";

    while (!getline(fileHandler, line).eof()) {
        std::vector<std::string> data;
        splitString(data, line, delim);
        Tutor t;
        t.ID = data.at(0);
        t.name = data.at(1);
        t.payRate = std::stof(data.at(2));
        t.rating = std::stof(data.at(3));
        t.phone = data.at(4);
        t.joinDate = *new Date(data.at(5));
        t.terminateDate = *new Date(data.at(6));
        t.center = getCenterByID(centerV, data.at(7));
        t.subject = getSubjectByID(subjectV, data.at(8));
        tutorV.push_back(t);
    }
    fileHandler.close();
}

void fileToSubject(std::vector<Subject> &subjectV, std::string filename) {
    std::fstream fileHandler(filename, std::ios::in);
    std::string line = "";
    std::string delim = "|";

    while (!getline(fileHandler, line).eof()) {
        std::vector<std::string> data;
        splitString(data, line, delim);
        Subject s;
        s.ID = data.at(0);
        s.name = data.at(1);
        subjectV.push_back(s);
    }
    fileHandler.close();
}

void fileToCenter(std::vector<Center> &centerV, std::string filename) {
    std::fstream fileHandler(filename, std::ios::in);
    std::string line = "";
    std::string delim = "|";

    while (!getline(fileHandler, line).eof()) {
        std::vector<std::string> data;
        splitString(data, line, delim);
        Center c;
        c.ID = data.at(0);
        c.name = data.at(1);
        centerV.push_back(c);
    }
    fileHandler.close();
}


void splitString(std::vector<std::string> &data, std::string str, std::string delim) {
    size_t start = 0;
    size_t end = str.find(delim);
    while (end != std::string::npos) {
        data.push_back(str.substr(start, end-start));
        start = end + delim.length();
        end = str.find(delim, start);
    }
    data.push_back(str.substr(start));
}

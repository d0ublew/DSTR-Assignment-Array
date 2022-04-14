#include <fstream>
#include <string>

#include "date.h"
#include "tutor.h"
#include "subject.h"
#include "center.h"
#include "file2struct.h"

extern SubjectArr* SUBJECT_ARR;
extern CenterArr* CENTER_ARR;

TutorArr* fileToTutor(std::string filename) {
    /*
     * Import data from text file to struct
     */

    size_t countLine = getLineNumber(filename);

    /*
     * create a dynamic array with size equals to total line number
     * of the given file
     */
    /* Tutor* tutorArr = (Tutor*) malloc(countLine * sizeof(Tutor)); */
    TutorArr* tutorArr = new TutorArr(countLine);

    std::fstream fileHandler;
    std::string line = "";
    std::string delim = "|";
    size_t idx = 0;

    fileHandler.open(filename, std::ios::in);

    while (!getline(fileHandler, line).eof()) {
        std::string* data = splitString(line, delim);
        Tutor* arr = tutorArr->arr;
        arr[idx].ID = data[0];
        arr[idx].name = data[1];
        arr[idx].payRate = std::stof(data[2]);
        arr[idx].rating = std::stof(data[3]);
        arr[idx].phone = data[4];
        arr[idx].joinDate = new Date(data[5]);
        arr[idx].terminateDate = new Date(data[6]);
        arr[idx].center = CENTER_ARR->getCenterByID(data[7]);
        arr[idx].subject = SUBJECT_ARR->getSubjectByID(data[8]);
        delete[] data;
        idx++;
    }

    fileHandler.close();
    return tutorArr;
}

SubjectArr* fileToSubject(std::string filename) {
    /*
     * Import data from text file to struct
     */

    size_t countLine = getLineNumber(filename);

    /*
     * create a dynamic array with size equals to total line number
     * of the given file
     */
    SubjectArr* subjectArr = new SubjectArr(countLine);

    std::fstream fileHandler;
    std::string line = "";
    std::string delim = "|";
    size_t idx = 0;

    fileHandler.open(filename, std::ios::in);

    while (!getline(fileHandler, line).eof()) {
        std::string* data = splitString(line, delim);
        Subject* arr = subjectArr->arr;
        arr[idx].ID = data[0];
        arr[idx].name = data[1];
        delete[] data;
        idx++;
    }

    fileHandler.close();

    return subjectArr;
}

CenterArr* fileToCenter(std::string filename) {
    /*
     * Import data from text file to struct
     */

    size_t countLine = getLineNumber(filename);

    /*
     * create a dynamic array with size equals to total line number
     * of the given file
     */
    CenterArr* centerArr = new CenterArr(countLine);

    std::fstream fileHandler;
    std::string line = "";
    std::string delim = "|";
    size_t idx = 0;

    fileHandler.open(filename, std::ios::in);

    while (!getline(fileHandler, line).eof()) {
        std::string* data = splitString(line, delim);
        Center* arr = centerArr->arr;
        arr[idx].ID = data[0];
        arr[idx].name = data[1];
        delete[] data;
        idx++;
    }

    fileHandler.close();

    return centerArr;
}

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

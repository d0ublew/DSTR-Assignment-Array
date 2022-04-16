#include <iostream>
#include <vector>

#include "tutor.h"
#include "file2struct.h"
#include "display.h"

std::vector<Subject> _SUBJECT;
std::vector<Center> _CENTER;
std::string TUTOR_FILE = "./data/tutor.txt";
std::string SUBJECT_FILE = "./data/subject.txt";
std::string CENTER_FILE = "./data/center.txt";


int main() {
    _SUBJECT = fileToSubject(SUBJECT_FILE);
    _CENTER = fileToCenter(CENTER_FILE);
    std::vector<Tutor> tutorV = fileToTutor(TUTOR_FILE);
    DisplayTutor(tutorV);

    return 0;
}

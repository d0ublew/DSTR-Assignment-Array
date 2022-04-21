#include <iostream>
#include <vector>

#include "admin_menu.h"
#include "file2struct.h"
#include "tutor.h"

const std::string TUTOR_FILE = "./data/tutor.txt";
const std::string SUBJECT_FILE = "./data/subject.txt";
const std::string CENTER_FILE = "./data/center.txt";
std::vector<Subject> _SUBJECT = fileToSubject(SUBJECT_FILE);
std::vector<Center> _CENTER = fileToCenter(CENTER_FILE);

int main() {
    std::vector<Tutor> tutorV = fileToTutor(TUTOR_FILE);
    startMenu(tutorV);

    return 0;
}


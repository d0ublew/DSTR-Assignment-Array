#include <iostream>
#include <vector>

#include "admin_menu.h"
#include "display.h"
#include "file2struct.h"
#include "search.h"
#include "sort.h"
#include "tutor.h"

const std::string TUTOR_FILE = "./tutor.txt";
const std::string SUBJECT_FILE = "./subject.txt";
const std::string CENTER_FILE = "./center.txt";
std::vector<Subject> _SUBJECT = fileToSubject(SUBJECT_FILE);
std::vector<Center> _CENTER = fileToCenter(CENTER_FILE);

int main() {
    std::vector<Tutor> tutorV = fileToTutor(TUTOR_FILE);

    if (_SUBJECT.size() == 0) {
        initSubject();
        _SUBJECT = fileToSubject(SUBJECT_FILE);
    }

    if (_CENTER.size() == 0) {
        initCenter();
        _CENTER = fileToCenter(CENTER_FILE);
    }

    if (tutorV.size() == 0) {
        initTutor();
        tutorV = fileToTutor(TUTOR_FILE);
    }

    startMenu(tutorV);
    return 0;
}


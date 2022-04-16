#include <iostream>
#include <vector>

#include "tutor.h"
#include "file2struct.h"
#include "display.h"
#include "add.h"


std::vector<Subject> _SUBJECT;
std::vector<Center> _CENTER;
std::string TUTOR_FILE = "./data/tutor.txt";
std::string SUBJECT_FILE = "./data/subject.txt";
std::string CENTER_FILE = "./data/center.txt";


int main() {
    _SUBJECT = fileToSubject(SUBJECT_FILE);
    _CENTER = fileToCenter(CENTER_FILE);
    std::vector<Tutor> tutorV = fileToTutor(TUTOR_FILE);
    
    Tutor tutor = addingInterface(tutorV);
    addToBack(tutorV, tutor);
    DisplayTutor(tutorV);
    /*std::vector<Tutor>::iterator it;
    for (it = tutorV.begin(); it != tutorV.end(); it++) {
        Tutor t = *it;
        std::cout << t.ID << '\n';
        std::cout << t.name << '\n';
        std::cout << t.payRate << '\n';
        std::cout << t.rating << '\n';
        std::cout << t.phone << '\n';
        std::cout << t.joinDate.ToString() << '\n';
        std::cout << t.terminateDate.ToString() << '\n';
        std::cout << t.center->ID << '\n';
        std::cout << t.center->name << '\n';
        std::cout << t.subject->ID << '\n';
        std::cout << t.subject->name << '\n';
    }
    tutorToFile(tutorV, "test.txt");*/
    
    return 0;
}

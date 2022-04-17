#include <iostream>
#include <vector>

#include "sort.h"
#include "tutor.h"
#include "file2struct.h"
#include "display.h"
#include "add.h"
#include "admin_menu.h"


const std::string TUTOR_FILE = "./data/tutor.txt";
const std::string SUBJECT_FILE = "./data/subject.txt";
const std::string CENTER_FILE = "./data/center.txt";
std::vector<Subject> _SUBJECT = fileToSubject(SUBJECT_FILE);
std::vector<Center> _CENTER = fileToCenter(CENTER_FILE);



int main() {
    
    _SUBJECT = fileToSubject(SUBJECT_FILE);
    _CENTER = fileToCenter(CENTER_FILE);
    std::vector<Tutor> tutorV = fileToTutor(TUTOR_FILE);
    startMenu();
    /* DisplayTutor(tutorV); */

    Node n;
    n.tutor = &tutorV.at(0);

    std::cout << n.tutor << '\n';
    std::cout << &(tutorV.at(0)) << '\n';

    Node a = *new Node(tutorV.at(0));
    std::cout << a.tutor << '\n';

    return 0;
}


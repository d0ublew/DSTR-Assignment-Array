#include <iostream>
#include <vector>

#include "tutor.h"
#include "file2struct.h"

std::vector<Subject> SUBJECT_;
std::vector<Center> CENTER_;

int main() {
    SUBJECT_ = fileToSubject("./data/subject.txt");
    CENTER_ = fileToCenter("./data/center.txt");
    std::vector<Tutor> tutorV = fileToTutor("./data/tutor.txt");
    std::vector<Tutor>::iterator it;
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
    /* Subject* s = getSubjectByID("S01"); */
    /* std::cout << s->name << '\n'; */
    return 0;
}

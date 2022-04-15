#include <iostream>
#include <vector>

#include "tutor.h"
#include "file2struct.h"

int main() {
    /* std::vector<Tutor>::iterator it; */
    /* std::vector<Tutor> v; */
    /* v.push_back(*new Tutor("T01", "Name")); */
    /* v.push_back(*new Tutor("T02", "emaN")); */
    /* for (it = v.begin(); it != v.end(); it++) { */
    /*     Tutor t = *it; */
    /*     std::cout << t.ID << ' ' << t.name << '\n'; */
    /* } */
    /* tutorToFile(v, "./test.dat"); */
    std::vector<Tutor> tutorV;
    fileToTutor(tutorV, "./test.dat");
    std::cout << tutorV.size() << '\n';
    /* for (it = tutorV.begin(); it != tutorV.end(); it++) { */
    /*     Tutor t = *it; */
    /*     std::cout << t.ID << ' ' << t.name << '\n'; */
    /* } */
    return 0;
}

#include <iostream>

#include "tutor.h"
#include "file2struct.h"
#include "subject.h"

SubjectArr* SUBJECT_ARR = fileToSubject("./subject.txt");
CenterArr* CENTER_ARR = fileToCenter("./center.txt");
TutorArr* TUTOR_ARR = fileToTutor("./tutor.txt");

int main() {
    TUTOR_ARR->Print();
    SUBJECT_ARR->Print();
    CENTER_ARR->Print();
    delete TUTOR_ARR;
    delete SUBJECT_ARR;
    delete CENTER_ARR;
    return 0;
}

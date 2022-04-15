#include <iostream>

#include "tutor.h"
#include "file2struct.h"
#include "subject.h"
#include "add.h"
#include "display.h"

SubjectArr* SUBJECT_ARR = fileToSubject("./data/subject.txt");
CenterArr* CENTER_ARR = fileToCenter("./data/center.txt");
TutorArr* TUTOR_ARR = fileToTutor("./data/tutor.txt");

int main() {

    

    DisplayTutor();

    /*TUTOR_ARR->Print();
    SUBJECT_ARR->Print();
    CENTER_ARR->Print();
    delete TUTOR_ARR;
    delete SUBJECT_ARR;
    delete CENTER_ARR;*/
    return 0;
}

#include <iostream>
#include <string>
#include <vector>

#include "search.h"
#include "sort.h"
#include "validate.h"

std::vector<Tutor> searchByID(std::vector<Tutor> &vec, std::string ID) {

    std::vector<Tutor> sortedVec = sortTutor(vec, &CompareTutorID, 'a');

    int start = 0;
    int end = sortedVec.size() - 1;

    Tutor t_temp;
    std::vector<Tutor> temp;

    while (start <= end) {
        int middle = (start + end) / 2;

        if (ID == sortedVec[middle].ID) {
            t_temp = sortedVec[middle];
            temp.push_back(t_temp);

            return temp;
        }

        if (sortedVec[middle].ID < ID) start = middle + 1;

        if (sortedVec[middle].ID > ID) end = middle - 1;
    }
    return temp;
}

std::vector<Tutor> searchByRating(std::vector<Tutor> &vec, float rt) {

    vec = sortTutor(vec, &CompareTutorRating, 'a');

    int start = 0;
    int end = vec.size() - 1;

    Tutor t_temp;
    std::vector<Tutor> temp;

    while (start <= end) {
        int middle = (start + end) / 2;

        if (rt == vec[middle].rating) {
            t_temp = vec[middle];
            temp.push_back(t_temp);

            return temp;
        }

        if (vec[middle].rating < rt) start = middle + 1;

        if (vec[middle].rating > rt) end = middle - 1;
    }
    return temp;
}

void validate_search(int ch) {
    std::vector<Tutor> vec;
    std::string ID;
    float rating;

    while (true) {

        if (ch == 1) {
            std::cout << "Enter Tutor ID (TXX): ";
            std::getline(std::cin, ID);
            if (!isTutorIDFormatCorrect(ID) && isTutorIDExisted(vec, ID)) {
                std::vector<Tutor> temp = searchByID(vec, ID);
            }
        } else if (ch == 2) {
            rating = getFloatInput("Enter Tutor rating: ");

            std::vector<Tutor> temp = searchByRating(vec, rating);
        } else {
            std::cout << "Please only input option 1 or 2." << std::endl;
        }
    }
}

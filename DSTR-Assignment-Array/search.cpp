#include<iostream>
#include<string>
#include<vector>


#include "search.h"
#include "sort.h"
#include "validate.h"


std::vector<Tutor> searchByID(std::vector<Tutor>& vec, std::string ID) {

    vec = sortTutor(vec, &CompareTutorID, 'a');

    int start = 0;
    int end = vec.size() - 1;

    Tutor t_temp;
    std::vector<Tutor> temp;


    while (start <= end) {
        int middle = (start + end) / 2;

        if (ID == vec[middle].ID) {
            t_temp = vec[middle];
            temp.push_back(t_temp);

            return temp;
        }

        if (vec[middle].ID < ID)
            start = middle + 1;


        if (vec[middle].ID > ID)
            end = middle - 1;

    }
    return temp;

}

std::vector<Tutor> searchByRating(std::vector<Tutor>& vec, float rt) {

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

        if (vec[middle].rating < rt)
            start = middle + 1;

        if (vec[middle].rating > rt)
            end = middle - 1;
    }
    return temp;
}


void validate_search(int ch) {
    std::vector<Tutor> vec;
    std::string id_tutor;
    float rating_tutor;

    while (true) {

        if (ch == 1) {
            std::cout << "Enter Tutor ID (TXX): ";
            std::getline(std::cin, id_tutor);
            if (!isTutorIDFormatCorrect(id_tutor) && isTutorIDExisted(vec, id_tutor)) {
                std::vector<Tutor> temp = searchByID(vec, id_tutor);
                std::cout << "output" /*enter output code*/ << std::endl;

            }
            else {
                std::cout << "wrong Tutor ID format" << std::endl;
            }
        }
        else if (ch == 2) {
            std::cout << "Enter Tutor rating: ";
            std::cin >> rating_tutor;

            if (checkFloatInput(rating_tutor)) {
                std::vector<Tutor> temp = searchByRating(vec, rating_tutor);
                std::cout << "output" /*enter output code*/ << std::endl;
            }
            else {
                std::cout << "wrong rating number format" << std::endl;
            }
        }
        else {
            std::cout << "Please only input option 1 or 2." << std::endl;
        }
    }

}
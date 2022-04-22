#pragma once

#include<string>
#include<vector>

#include "tutor.h"


std::vector<Tutor> searchByID(std::vector<Tutor>& search_vec, std::string search_id);

std::vector<Tutor> searchByRating(std::vector<Tutor>& search_vec, float search_rating);

void validate_search(int choice);

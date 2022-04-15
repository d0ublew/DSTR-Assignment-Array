#include <iostream>
#include <vector>

#include "tutor.h"

int main() {
    std::vector<Tutor>::iterator it;
    std::vector<Tutor> v;
    v.push_back(*new Tutor("T01", "Name"));
    v.push_back(*new Tutor("T02", "emaN"));
    for (it = v.begin(); it != v.end(); it++) {
        Tutor t = *it;
        std::cout << t.ID << ' ' << t.name << '\n';
    }
    return 0;
}

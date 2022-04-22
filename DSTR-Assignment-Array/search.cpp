#include <iostream>
#include <string>
#include <vector>

#include "search.h"
#include "sort.h"
#include "validate.h"

int binarySearch(std::vector<Tutor> &v, Tutor t,
                 int (*CompareFn)(Tutor &, Tutor &), int offset) {
    int start = 0;
    int end = v.size() - 1;
    while (start <= end && end > 0) {
        int mid = (start + end) / 2;
        Tutor t2 = v.at(mid);
        int result = (*CompareFn)(t, t2);
        if (result == 0)
            return mid + offset;
        else if (result > 0)
            start = mid + 1;
        else if (result < 0)
            end = mid - 1;
    }
    return -1;
}

std::vector<Tutor> searchTutor(std::vector<Tutor> &tutorV, Tutor t,
                               int (*CompareFn)(Tutor &, Tutor &)) {
    std::vector<Tutor> v = sortTutor(tutorV, (*CompareFn), 'a');
    int idx = binarySearch(v, t, (*CompareFn));

    if (idx == -1) return slice(v, 0, -1);

    int temp = idx;
    int low;
    while (temp != -1) {
        std::vector<Tutor> sub = slice(v, 0, temp - 1);
        low = temp;
        temp = binarySearch(sub, t, (*CompareFn));
    }

    temp = idx;
    int high;
    while (temp != -1) {
        std::vector<Tutor> sub = slice(v, temp + 1, v.size() - 1);
        high = temp;
        temp = binarySearch(sub, t, (*CompareFn), high + 1);
    }

    return slice(v, low, high);
}

std::vector<Tutor> slice(std::vector<Tutor> &v, size_t start, size_t end) {
    std::vector<Tutor>::iterator low = v.begin() + start;
    std::vector<Tutor>::iterator high = v.begin() + end + 1;

    std::vector<Tutor> sub(low, high);
    return sub;
}

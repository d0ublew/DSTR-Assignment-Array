#include <iostream>
#include <string>
#include <vector>

#include "search.h"
#include "sort.h"
#include "validate.h"

int binarySearch(std::vector<Tutor *> &v, Tutor t, int (*CompareFn)(Tutor &, Tutor &))
{
    int start = 0;
    int end = (int)v.size() - 1;
    while (start <= end && end >= 0)
    {
        int mid = (start + end) / 2;
        Tutor t2 = *v.at(mid);
        int result = (*CompareFn)(t, t2);
        if (result == 0)
            return mid;
        else if (result > 0)
            start = mid + 1;
        else if (result < 0)
            end = mid - 1;
    }
    return -1;
}

std::vector<Tutor *> searchTutor(std::vector<Tutor *> &tutorV, Tutor t, int (*CompareFn)(Tutor &, Tutor &))
{
    std::vector<Tutor *> v = sortTutor(tutorV, (*CompareFn), 'a');
    int idx = binarySearch(v, t, (*CompareFn));

    if (idx == -1) return {};

    int temp = idx;
    int low;
    /**
     * Keep doing binary search on the left part of the array to find the
     * lowest index of matching result
     */
    while (temp != -1)
    {
        std::vector<Tutor *> sub = slice(v, 0, temp - 1);
        low = temp;
        temp = binarySearch(sub, t, (*CompareFn));
    }

    temp = idx;
    int high;
    /**
     * Keep doing binary search on the right part of the array to find the
     * highest index of matching result
     */
    while (temp != -1)
    {
        std::vector<Tutor *> sub = slice(v, temp + 1, (int)v.size() - 1);
        high = temp;
        temp = binarySearch(sub, t, (*CompareFn));
        if (temp != -1) temp += high + 1;
    }

    return slice(v, low, high);
}

std::vector<Tutor *> slice(std::vector<Tutor *> &v, int start, int end)
{
    if (end == -1) return {};
    std::vector<Tutor *>::iterator low = v.begin() + start;
    std::vector<Tutor *>::iterator high = v.begin() + end + 1;

    /**
     * We need to plus 1 to the end since the vector takes end parameter as
     * exclusive index, [low, high)
     */
    std::vector<Tutor *> sub(low, high);
    return sub;
}

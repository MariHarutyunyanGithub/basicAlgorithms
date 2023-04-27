// Implement a program to find the largest value in an array recursively.

#include <iostream>
#include <vector>

int findLargestValue(std::vector<int> vec, int size)
{
    // int max = vec[0];
    // for (int i{1}; i < vec.size(); ++i) {
    //     if (vec[i] > max) {
    //         max = vec[i];
    //     }
    // }
    // return max;


     if (size == 1) {
        return vec[size - 1];
    }
    else {
        int sub_max = findLargestValue(vec, size - 1);
        return (vec[size - 1] > sub_max) ? vec[size - 1] : sub_max;
    }
}

int main() {
    std::vector<int> vec = {1, 15, 7, 23, 4, 29, 18, 3};
    std::cout << findLargestValue(vec, vec.size()) << std::endl;
}
// Implement the binary search algorithm for numeric arrays.

#include <iostream>
#include <vector>

int binarySearch(std::vector<int> vec, int left, int right, int key) 
{
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (vec[mid] == key) {
            return mid;
        }
        if (vec[mid] > key) {
            return binarySearch(vec, left, mid - 1, key);
        }
        return binarySearch(vec, mid + 1, right, key);
    }
    return -1;
}

int main() {
    std::vector<int> vec = {1, 2, 3, 8, 9};
    std::cout << binarySearch(vec, 0, vec.size() - 1, 2) << std::endl;
}
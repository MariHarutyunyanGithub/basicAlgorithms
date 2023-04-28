//  implement mergeSort algorithm

#include <iostream>
#include <vector>

void merge(std::vector<int>& vec, int left, int mid, int right)
{
    int start1 = left, end1 = mid;
    int start2 = mid + 1, end2 = right;
    int index{};
    std::vector<int> tmp(right - left + 1);

    while (start1 <= end1 && start2 <= end2) {
        if (vec[start1] <= vec[start2]) {
            tmp[index++] = vec[start1++];
        } else {
            tmp[index++] = vec[start2++];
        }
    }
    while (start1 <= end1) {
        tmp[index++] = vec[start1++];
    }
    while (start2 <= end2) {
        tmp[index++] = vec[start2++];
    }
    for (int i{left}, k{}; i <= right;) {
        vec[i++] = tmp[k++];
    }
}

void mergeSort(std::vector<int>& vec, int left, int right)
{
    if (left < right) {    
        int mid = left + (right - left) / 2;
        mergeSort(vec, left, mid);
        mergeSort(vec, mid + 1, right);
        merge(vec, left, mid, right);
    }
}

int main() {
    std::vector<int> vec = {9, 2, 5, 3, 4, 7};
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    mergeSort(vec, 0, vec.size() - 1);
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

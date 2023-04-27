// Implement a program to find the kth smallest number in an array recursively.

#include <iostream>
#include <vector>

int kthSmallest(std::vector<int> vec, int k)
{
    if (vec.size() == 1) {
        return vec[0];
    }
    
    int pivot = vec[0];
    std::vector<int> left, right;
    for (int i{1}; i < vec.size(); i++) {
        if (vec[i] < pivot) {
            left.push_back(vec[i]);
        } else {
            right.push_back(vec[i]);
        }
    }    
    if (left.size() >= k) {
        return kthSmallest(left, k);
    }
    return kthSmallest(right, k - left.size() - 1);
}

int main() {
    std::vector<int> vec = {1, 8, 5, 4, 1, 2, 6, 7, 6};
    int k = 3;
    std::cout << kthSmallest(vec, k) << std::endl;
}
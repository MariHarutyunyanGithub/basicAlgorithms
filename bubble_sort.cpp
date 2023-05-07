#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& vec)
{
    for (int i{}; i < vec.size(); ++i) {
        bool sorted = true;
        for (int j{}; j < vec.size() - i - 1; ++j) {
            if (vec[j] > vec[j + 1]) {
                sorted = false;
                std::swap(vec[j], vec[j + 1]);
            }
        }
        if (sorted) {
            return;
        }
    }
}

int main() {
    std::vector<int> vec{0, 1, 2, 5, 4, 6, 7, 9, 7, 9};
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    bubbleSort(vec);
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}
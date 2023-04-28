#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& vec)
{
    for (int i{}; i < vec.size(); ++i) {
        for (int j{1}; j < vec.size() - i - 1; ++j) {
            if (vec[j] > vec[j + 1]) {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }
}

int main() {
    std::vector<int> vec{1, 2, 5, 4, 8, 7, 3};
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
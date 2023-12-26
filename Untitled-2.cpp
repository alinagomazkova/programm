#include <iostream>
#include <vector>
#include <cmath>

bool findIndexValueDiff(const std::vector<int>& nums, int indexDiff, int valueDiff) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (abs(i - j) <= indexDiff && abs(nums[i] - nums[j]) <= valueDiff) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    int indexDiff = 2;
    int valueDiff = 3;

    if (findIndexValueDiff(nums, indexDiff, valueDiff)) {
        std::cout << "���� � ��������� ��������� ����������." << std::endl;
    } else {
        std::cout << "���� � ��������� ��������� �� ����������." << std::endl;
    }

    return 0;
}
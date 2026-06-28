#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

class Solution {
public:
  int findMe(std::vector<int> &vec, int val, int j) {
    int i = 0;
    while (i < vec.size()) {
      if (i == j) {
        i++;
        continue;
      }
      if (vec[i] == val) {
        return i;
      }
      i++;
    }
    return -1;
  }
  std::vector<int> twoSum(std::vector<int>& numbers, int target) {
    std::vector<int> result;
    int i = 0;
    while (i < numbers.size()) {
      int val = target - numbers[i];
      int index = findMe(numbers, val, i);
      if (index != -1) {
        result.push_back(i + 1);
        result.push_back(index + 1);
        break;
      }
      i++;
    }
    return result;
  }
};



#include <vector>
#include <iostream>

class Solution {
public:

    int findIndex(int val, std::vector<int> arr, int j) {
      for (int i = 0; i < arr.size(); i++) {
        if (i == j) {
          continue;
        }
        if (val == arr[i]) {
          return i;
        }
      }
      return -1;
    }
    std::vector<int> twoSum(std::vector<int>& nums, int target) {   
      std::vector<int> arr;

      bool flag = false;
      for (int i = 0; i < nums.size(); i++) {
        int value = target - nums[i];
        int index = findIndex(value, nums, i);
        if (index != -1) {
          if (index < i) {
            arr.push_back(index);
            arr.push_back(i);
          }
          else {
            arr.push_back(i);
            arr.push_back(index);
          }
          return arr;
        }
      }
      return arr;
    }
};

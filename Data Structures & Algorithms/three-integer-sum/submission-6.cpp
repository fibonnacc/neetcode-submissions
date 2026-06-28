#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    int search(std::vector<int> vec, int j, int k, int value) {
      int i = 0;
      while (i < vec.size()) {
        if (i != k && i != j)
        {
          if (vec[i] == value) {
            return i;
          }
        }
        i++;
      }
      return -1;
    }

    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
      int i = 0;
      std::vector<std::vector<int> > vec;
      std::sort(nums.begin(), nums.end());
      while (i < nums.size() - 1) {
        int j = 0;
        while (j < nums.size() - 1) {
          if (j == i)
          {
            j++;
            continue;
          }
          int value = nums[i] + nums[j];
          int opposite = value * -1;
          int index = search(nums, i, j, opposite);
          if (index != -1) {
            std::vector<int> helper = {nums[i], nums[j], opposite};
            std::sort(helper.begin(), helper.end());
            bool flag = false;
            int f = 0;
            while (f < vec.size()) {
              std::vector<int> thing = vec[f];
              std::sort(thing.begin(), thing.end());
              if (thing == helper)
              {
                flag = true;
                break;
              }
              f++;
            }
            if (flag == false) {
              // std::cout << "{" << nums[i] << ", " << nums[j] << ", " << opposite << "} " << std::endl;
              vec.push_back(helper);
            }
          }
          j++;
        }
        i++;
      }
      // std::cout << std::endl;
      return vec;
    }
};
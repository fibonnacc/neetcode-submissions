#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
      std::vector<int> vec;

      std::unordered_map<int, int> mapp;

      for (int i = 0; i < nums.size(); i++) {
        mapp[nums[i]]++;
      }
      std::vector<std::pair<int, int>> v(mapp.begin(), mapp.end());

      std::sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
          return a.second > b.second;
          }
      );

      int i = 0;
      for (auto num : v) {
        if (i < k) {
          vec.push_back(num.first);
          i++;
        }
        else {
          break;
        }
      }

      // for (int i = 0; i < vec.size(); i++) {
      //   std::cout << vec[i] << " " ;
      // }
      // std::cout << std::endl;
      return vec;
    }
};

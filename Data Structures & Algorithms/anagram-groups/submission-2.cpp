#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
      std::map<std::string, std::vector<std::string>> mapp;
      std::vector<std::vector<std::string>> vec;

      for (int i = 0; i < strs.size(); i++) {

        std::string str = strs[i];
        std::sort(str.begin(), str.end());
        mapp[str].push_back(strs[i]);
      }

      for (auto num: mapp) {
        vec.push_back(num.second);
      }
      return vec;
    }
};

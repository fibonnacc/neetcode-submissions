
class Solution {
public:
    std::string encode(std::vector<std::string>& strs) {
      std::string res("");
      for (size_t i = 0; i < strs.size(); i++) {
        std::string delemiter = std::to_string(strs[i].size()) + "#"; 
        res += delemiter + strs[i];
      }
      return res;
    }

    std::vector<std::string> decode(std::string s) {
      std::vector<std::string> vec;
      size_t i = 0;
      while ( i < s.size()) {
        int start = 0;
        if (s[i] == '#') {
          std::string sub = s.substr(0, i);
          start = i + 1;
          int value = std::atoi(sub.c_str());
          std::string str = s.substr(start, value);
          vec.push_back(str);
          s.erase(0, i + value + 1);
          i = 0;
        }
        i++;
      }
      return vec;
    }
};


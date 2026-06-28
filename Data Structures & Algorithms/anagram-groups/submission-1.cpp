class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
      std::unordered_map<std::string, std::vector<std::string> > Arr;
      for (std::string s : strs) {
        std::string copy = s;
        std::sort(copy.begin(), copy.end());
        Arr[copy].push_back(s);
      }

      std::vector<std::vector<std::string>> room;

      for (std::unordered_map<std::string, std::vector<std::string>>::iterator it = Arr.begin(); it != Arr.end(); ++it) {
        room.push_back(it->second);
      }
      return room;
    }
};

#include <iostream>
#include <map>
#include <stack>

class Solution {
public:
    char reverse(char c) {
      if (c == '{')
        return '}';
      else if (c == '(') {
        return ')';
      }
      else if(c == '[') 
        return ']';
      return 'x';
    }
    bool isValid(std::string s) {
        std::stack<char> st;
        if (s.size() < 2) {
            return false;
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '{' || s[i] == '(' || s[i] == '[')
                st.push(s[i]);
            else {
                if (st.empty())
                    return false;

                char top = st.top();
                if (reverse(top) == s[i])
                    st.pop();
                else
                    return false;
            }
        }
        return st.empty();
    }
};

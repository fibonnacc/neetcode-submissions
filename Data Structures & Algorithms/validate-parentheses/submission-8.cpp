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
        for (int i = 0; i < s.size(); i++) {
          if (st.empty() ||s[i] == '{' || s[i] == '(' || s[i] == '[')
            st.push(s[i]);
          else
           {
              char top = st.top();
              if (reverse(top) == s[i])
                st.pop();
              else
                st.push(s[i]);
          }
        }
        return st.empty();
    }
};


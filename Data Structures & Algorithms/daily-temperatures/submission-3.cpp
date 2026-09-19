class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> vec(temperatures.size());
        std::stack<int> st;
        int i = 0;
        while (i < temperatures.size()) {
            if (!st.empty() && temperatures[i] > temperatures[st.top()]) {
              int idx = st.top();
              st.pop();
              vec[idx] = i - idx;
            }
            else {
              st.push(i);
              i++;
            }
        }
        return vec;
    }
};


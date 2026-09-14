class Solution {
public:
    bool isSymbol(string symbol) {
        return (symbol == "+" || symbol == "-" 
            || symbol == "*" || symbol == "/");
    }
    int evalRPN(vector<string>& tokens) {
        std::stack<int> st;
        int result = 0;
        for (int i = 0; i < tokens.size(); i++) {
            if (isSymbol(tokens[i])) {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if (tokens[i] == "+") {
                    result = b + a;
                }
                else if (tokens[i] == "-") {
                    result = b - a;
                }
                else if (tokens[i] == "*") {
                    result = b * a;
                }
                else if (tokens[i] == "/") {
                    result = b / a;
                }
                st.push(result);
            }
            else {
                st.push(std::stoi(tokens[i]));
            }
        }
        return st.top();
    }
};

class MinStack {
public:
    std::stack<int> st;
    std::stack<int> st_min;

    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
        if (st_min.empty()) {
            st_min.push(val);
        }
        else {
            if (st_min.top() >= val)
            {
                st_min.push(val);
            }
        }
    }
    
    void pop() {
        if (st.empty())
            return ;
        if (st_min.top() == st.top()) {
            st_min.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    

    int getMin() {
        return st_min.top();
    }
};

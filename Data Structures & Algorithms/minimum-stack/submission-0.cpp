class MinStack {
    stack<pair<int, int>> st;
public:
    MinStack() {
    }
    
    void push(int val) {
        int mi = val;
        
        if (!st.empty())
        {
            mi = min(st.top().second, mi);
        }

        st.push({val, mi});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

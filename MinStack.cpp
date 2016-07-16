class MinStack {
private:
    stack<int> stac;
    stack<int> minS;
public:
    /** initialize your data structure here. */
    void push(int x) {
        stac.push(x);
        if (minS.empty() || x <= minS.top()) { // equal sign is important
            minS.push(x);
        }
    }
    
    void pop() {
        int num = top();
        stac.pop();
        if (num == minS.top()) {
            minS.pop();
        }
    }
    
    int top() {
        return stac.top();
    }
    
    int getMin() {
        return minS.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
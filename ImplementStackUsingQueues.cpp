class Stack {
public:
    queue<int> main, sub;
    
    // Push element x onto stack.
    void push(int x) {
        // dump main to sub
        while (!main.empty()) {
            sub.push(main.front());
            main.pop();
        }
        // put new element
        main.push(x);
        // dump sub to main
        while (!sub.empty()) {
            main.push(sub.front());
            sub.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        if (!main.empty()) {
            main.pop();
        }
    }

    // Get the top element.
    int top() {
        if (!main.empty()) {
            return main.front();
        }
        return 0;
    }

    // Return whether the stack is empty.
    bool empty() {
        return main.empty();
    }
};
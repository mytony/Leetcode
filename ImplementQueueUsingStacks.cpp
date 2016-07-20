class Queue {
public:
    stack<int> main, sub;
    
    // Push element x to the back of queue.
    void push(int x) {
        // dump all elements in main stack into sub stack
        while (!main.empty()) {
            sub.push(main.top());
            main.pop();
        }
        
        // put new element to the bottom of main stack
        main.push(x);
        
        // dump back the elements in sub stack
        while (!sub.empty()) {
            main.push(sub.top());
            sub.pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (!main.empty()) {
            main.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        if (!main.empty()) {
            return main.top();
        }
        return 0;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return main.empty();
    }
};
class MyQueue {
private:
    stack<int> inSt;
    stack<int> outSt;
    int itemCount;

public:
    MyQueue() 
    {
        itemCount = 0;
    }
    
    void push(int x)
    {
        while (!outSt.empty()) {
            inSt.push(outSt.top());
            ++itemCount;
            outSt.pop();
        }

        inSt.push(x);
        ++itemCount;
    }
    
    int pop()
    {
        peek();
        int topItem = outSt.top();
        outSt.pop();
        --itemCount;

        return topItem;
    }
    
    int peek()
    {
        while (!inSt.empty()) {
            outSt.push(inSt.top());
            inSt.pop();
        }

        return outSt.top();
    }
    
    bool empty() 
    {
        return (itemCount == 0);    
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

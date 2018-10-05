#include <iostream>

using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    stack<int> S1, S2;
    int front;
    /** Push element x to the back of queue. */
    void push(int x) {
        if(S1.empty())
            front = x;
        S1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(S2.empty()){
            while(!S1.empty()){
                S2.push(S1.top());
                S1.pop();
            }
        }
        int temp = S2.top();
        S2.pop();
        return temp;
    }

    /** Get the front element. */
    int peek() {
        if(!S2.empty())
            return S2.top();
        return front;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return S1.empty() && S2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

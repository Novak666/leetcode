#include <iostream>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    stack<int> S1, S2;

    void push(int x) {
        S1.push(x);
        if(S2.empty() || x <= getMin())
            S2.push(x);
    }

    void pop() {
        if(S1.top() == getMin())
            S2.pop();
        S1.pop();
    }

    int top() {
        return S1.top();
    }

    int getMin() {
        return S2.top();
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

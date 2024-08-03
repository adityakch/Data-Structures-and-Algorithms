#include <bits/stdc++.h>

using namespace std;

// using tw0 stacks
// 1) s1 to s2 (2) x to s1 (3) s2 to s1
class MyQueue
{
    stack<int> stk;
    stack<int> stk2;

public:
    MyQueue()
    {
        stk;
        stk2;
    }

    void push(int x)
    {
        while (!stk.empty())
        {
            stk2.push(stk.top());
            stk.pop();
        }

        stk.push(x);

        while (!stk2.empty())
        {
            stk.push(stk2.top());
            stk2.pop();
        }
    }

    int pop()
    {
        int val = stk.top();
        stk.pop();
        return val;
    }

    int peek()
    {
        return stk.top();
    }

    bool empty()
    {
        return stk.size();
    }
};

int main()
{

    MyQueue q;
    q.push(4);
    q.push(14);
    q.push(24);
    q.push(34);
    cout << "The peek of the queue before deleting any element " << q.peek() << endl;
    cout << "The first element to be deleted " << q.pop() << endl;
    cout << "The peek of the queue after deleting an element " << q.peek() << endl;

    return 0;
}
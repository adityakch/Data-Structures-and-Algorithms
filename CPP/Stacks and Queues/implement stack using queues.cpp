#include <bits/stdc++.h>

using namespace std;

// using two queues
class MyStack1
{
    queue<int> q1;
    queue<int> q2;

public:
    MyStack1()
    {
        q1;
        q2;
    }
    void push(int x)
    {
        q2.push(x);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop()
    {
        int val = q1.front();
        q1.pop();
        return val;
    }

    int top()
    {
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};

// using single queue
class MyStack2
{
    queue<int> q1;

public:
    MyStack2()
    {
        q1;
    }
    void push(int x)
    {
        q1.push(x);
        int size = q1.size();
        while (size > 1)
        {
            q1.push(q1.front());
            q1.pop();
            size--;
        }
    }

    int pop()
    {
        int val = q1.front();
        q1.pop();
        return val;
    }

    int top()
    {
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};

int main()
{

    MyStack2 q;
    q.push(4);
    q.push(14);
    q.push(24);
    q.push(34);
    cout << "The peek of the queue before deleting any element " << q.top() << endl;
    cout << "The first element to be deleted " << q.pop() << endl;
    cout << "The peek of the queue after deleting an element " << q.top() << endl;

    return 0;
}
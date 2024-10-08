#include <bits/stdc++.h>

using namespace std;

class MyQueue
{
    int start, end;
    int currSize, maxSize;
    int *arr;

public:
    MyQueue()
    {
        arr = new int[20];
        currSize = 0;
        start = -1;
        end = -1;
    }

    MyQueue(int maxSize)
    {
        (*this).maxSize = maxSize;
        arr = new int[maxSize];
        currSize = 0;
        start = -1;
        end = -1;
    }

    void push(int val)
    {
        if (currSize == maxSize)
        {
            cout << "Queue is full" << endl;
            exit(1);
        }
        if (end == -1)
        {
            start = 0;
            end = 0;
        }
        else
        {
            end = (end + 1) % maxSize;
        }

        arr[start] = val;
        cout << "The element pushed is " << val << endl;
        currSize++;
    }

    int pop()
    {
        if (start == -1)
        {
            cout << "Queue is empty" << endl;
        }
        int popped = arr[start];

        if (currSize == 1)
        {
            start = -1;
            end = -1;
        }
        else
        {
            start = (start + 1) % maxSize;
        }
        currSize--;

        return popped;
    }

    int top()
    {
        if (start == -1)
        {
            cout << "Queue is empty" << endl;
            exit(1);
        }

        return arr[start];
    }

    int size()
    {
        return currSize;
    }
};

int main()
{

    MyQueue q(6);
    q.push(4);
    q.push(14);
    q.push(24);
    q.push(34);
    cout << "The peek of the queue before deleting any element " << q.top() << endl;
    cout << "The size of the queue before deletion " << q.size() << endl;
    cout << "The first element to be deleted " << q.pop() << endl;
    cout << "The peek of the queue after deleting an element " << q.top() << endl;
    cout << "The size of the queue after deleting an element " << q.size() << endl;

    return 0;
}
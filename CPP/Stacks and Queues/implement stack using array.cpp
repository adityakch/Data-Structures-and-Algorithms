#include <bits/stdc++.h>

using namespace std;

class MyStack {
    int top;
    int * arr;
    int size;

    public: 
        MyStack() {
            top = -1;
            size = 10;
            arr = new int[size];
        }
    
        void push(int val) {
            top++;
            arr[top] = val;
        }

        int pop() {
            int val = arr[top];
            top--;
            return val;
        }

        int Top() {
            return arr[top];
        }

        int Size() {
            return top+1;
        }
};

int main() {

    MyStack st;
    st.push(1);
    st.push(3);
    st.push(2);
    st.push(8);

    cout << st.Top() << endl;
    cout << st.Size() << endl;
    cout << st.pop() << endl;
    cout << st.Top() << endl;
    cout << st.Size() << endl;

    return 0;
}
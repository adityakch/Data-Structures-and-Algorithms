#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *convertArr2LL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *curr = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);

        curr->next = temp;
        curr = temp;
    }
    return head;
}

void print(Node *head)
{
    Node *curr = head;

    while (curr)
    {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << "null" << endl;
}

Node *reverse(Node *head)
{
    Node *prev = nullptr, *curr = head, *nextNode = nullptr;

    while (curr)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

// TC: O(n) + O(n), SC: O(n)
bool isPalindrome(Node *head)
{
    if (!head || !head->next)
        return true;
    Node *curr = head;
    stack<int> stk;

    while (curr) // O(n)
    {
        stk.push(curr->data);
        curr = curr->next;
    }

    Node *temp = head;
    while (temp) // O(n)
    {
        if (temp->data != stk.top())
        {
            return false;
        }
        temp = temp->next;
        stk.pop();
    }
    return true;
}

// k = n/2,  TC: O(k) + O(k) + O(k), SC: O(1)
bool isPalindrome2(Node *head)
{
    if (!head || !head->next)
        return true;

    // step-1: find middle node
    Node *slow = head, *fast = head;

    while (fast->next && fast->next->next) // O(k)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // step-2: reverse secondhalf
    Node *secondHalf = reverse(slow->next); // O(k)

    // step-3: traverse secondhalf
    Node *firstHalf = head;
    while (secondHalf) // O(k)
    {
        if (firstHalf->data != secondHalf->data)
        {
            reverse(secondHalf);
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    reverse(secondHalf);
    return true;
}

int main()
{
    vector<int> arr = {1, 2, 2, 1};
    Node *head = convertArr2LL(arr);
    print(head);

    cout << isPalindrome2(head) << endl;

    return 0;
}
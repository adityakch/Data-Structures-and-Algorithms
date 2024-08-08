#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
};

Node *convertArr2LL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *curr = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        curr->next = temp;
        curr = curr->next;
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

Node *reverseLL(Node *head, int left, int right)
{
    Node *dummy = new Node(0, head);
    Node *prev = dummy;

    for (int i = 0; i < left - 1; i++)
    {
        prev = prev->next;
    }

    Node *curr = prev->next, *forw = nullptr;

    for (int i = 0; i < right - left; i++)
    {
        forw = curr->next;
        curr->next = forw->next;
        forw->next = prev->next;
        prev->next = forw;
    }

    return dummy->next;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int left = 2, right = 4;

    Node *head = convertArr2LL(arr);
    print(head);

    head = reverseLL(head, left, right);
    print(head);

    return 0;
}
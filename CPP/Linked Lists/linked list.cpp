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

int lengthOfLL(Node *head)
{
    Node *curr = head;
    int count = 0;

    while (curr)
    {
        count++;
        curr = curr->next;
    }

    return count;
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

int main()
{
    vector<int> arr = {2, 4, 12, 8, 3};
    Node *head = convertArr2LL(arr);

    print(head);
    cout << lengthOfLL(head) << endl;

    return 0;
}
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

Node *rotateLL(Node *head, int k)
{
    Node *dummy = new Node(0, head);
    Node *prev = dummy, *curr = head;

    int len = 0;
    while (curr)
    {
        len++;
        curr = curr->next;
    }

    k = k % len;

    if (k == 0)
        return head;

    // maintain k dist between prev and curr nodes
    int count = 0;
    curr = head;

    while (curr->next)
    {
        count++;
        if (count >= k)
        {
            prev = prev->next;
        }
        curr = curr->next;
    }

    curr->next = dummy->next;
    dummy->next = prev->next;
    prev->next = nullptr;

    return dummy->next;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 1;

    Node *head = convertArr2LL(arr);
    print(head);

    head = rotateLL(head, k);
    print(head);
}
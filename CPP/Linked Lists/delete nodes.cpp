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

Node *deleteAtStart(Node *head)
{
    if (head == NULL)
        return head;

    Node *temp = head;
    head = head->next;
    delete temp;

    return head;
}

Node *deleteAtEnd(Node *head)
{
    Node *curr = head;

    while (curr->next->next)
    {
        curr = curr->next;
    }
    curr->next = nullptr;

    return head;
}

Node *deleteAtK(Node *head, int k)
{
    if (head == NULL)
        return head;

    if (k == 1)
        return deleteAtStart(head);

    int count = 0;
    Node *curr = head;
    Node *prev = NULL;

    while (curr)
    {
        count++;
        if (count == k)
        {
            prev->next = prev->next->next;
            delete curr;
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    return head;
}

Node *deleteValue(Node *head, int val)
{
    if (head == NULL)
        return head;

    if (head->data == val)
    {
        return deleteAtStart(head);
    }

    Node *curr = head;
    Node *prev = NULL;

    while (curr)
    {
        if (curr->data == val)
        {
            prev->next = prev->next->next;
            delete curr;
            break;
        }
        prev = curr;
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

int main()
{
    vector<int> arr = {2, 4, 12, 8, 3};
    Node *head = convertArr2LL(arr);

    print(head);
    head = deleteValue(head, 2);
    print(head);

    return 0;
}
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

Node *insertAtStart(Node *head, int val)
{
    Node *curr = new Node(val);

    curr->next = head;

    return curr;
}

Node *insertAtEnd(Node *head, int val)
{
    if (head == NULL)
    {
        return new Node(val);
    }

    Node *curr = head;
    Node *temp = new Node(val);

    while (curr->next)
    {
        curr = curr->next;
    }
    curr->next = temp;

    return head;
}

Node *insertAtK(Node *head, int val, int k)
{
    if (head == NULL)
    {
        if (k == 1)
        {
            return new Node(val);
        }
        else
        {
            return head;
        }
    }

    if (k == 1)
    {
        return new Node(val, head);
    }

    Node *curr = head;
    int count = 0;

    while (curr)
    {
        count++;

        if (count == k - 1)
        {
            Node *new_node = new Node(val);
            new_node->next = curr->next;
            curr->next = new_node;
            break;
        }
        curr = curr->next;
    }

    return head;
}

Node *insertBeforeEle(Node *head, int val, int ele)
{
    if (head == NULL)
    {
        return head;
    }

    if (head->data == ele)
    {
        return insertAtStart(head, val);
    }

    Node *curr = head;
    while (curr)
    {
        Node *new_node = new Node(val);
        if (curr->next->data == ele)
        {
            new_node->next = curr->next;
            curr->next = new_node;
            break;
        }
        curr = curr->next;
    }

    return head;
}

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

int main()
{
    vector<int> arr = {2, 4, 12, 8, 3};
    Node *head = convertArr2LL(arr);
    print(head);

    head = insertAtStart(head, 5);
    print(head);

    head = insertAtEnd(head, 10);
    print(head);

    head = insertBeforeEle(head, 23, 10);
    print(head);

    return 0;
}
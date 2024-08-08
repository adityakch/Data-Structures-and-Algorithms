#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int val1)
    {
        data = val1;
        next = nullptr;
    }

public:
    Node(int val1, Node *next1)
    {
        data = val1;
        next = next1;
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

Node *reverse(Node *head)
{
    Node *curr = head, *prev = nullptr, *nextNode = nullptr;

    while (curr)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

Node *reorderList(Node *head)
{
    if (!head || !head->next)
        return head;

    Node *dummy = new Node(0, head);
    Node *first = head, *slow = head, *fast = head;

    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *second = slow->next;
    slow->next = nullptr;

    second = reverse(second);

    while (second)
    {
        Node *temp1 = first->next;
        Node *temp2 = second->next;

        first->next = second;
        second->next = temp1;

        first = temp1;
        second = temp2;
    }

    return dummy->next;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node *head = convertArr2LL(arr);
    print(head);

    head = reorderList(head);
    print(head);

    return 0;
}
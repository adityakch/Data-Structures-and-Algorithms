class Node:
    def __init__(self, data) -> None:
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self) -> None:
        self.head = None

    def append(self, val):
        new_node = Node(val)

        if not self.head:
            self.head = new_node
            return
        
        curr = self.head
        while curr.next:
            curr = curr.next
        curr.next = new_node
        
    def print_list(self):
        curr = self.head

        while curr:
            print(curr.data,end=" -> ")
            curr = curr.next
        print('None')


    def reorder_list(self, head):
        slow = fast = head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        second = slow.next
        print(slow.data)

        prev = slow.next = None
        
        while second:
            next_node = second.next
            second.next = prev
            prev = second
            second = next_node

        first = head
        second = prev

        while second:
            temp1 = first.next
            temp2 = second.next

            first.next = second
            second.next = temp1

            first = temp1
            second = temp2

lst = LinkedList()
arr = [1,2,3,4,5,6]

for i in arr:
    lst.append(i)

lst.print_list()
lst.reorder_list(lst.head)
lst.print_list()
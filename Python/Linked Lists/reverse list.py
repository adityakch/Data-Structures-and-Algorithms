class Node:
    def __init__(self,data) -> None:
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self) -> None:
        self.head = None

    def append(self,val):
        new_node = Node(val)

        if not self.head:
            self.head = new_node
            return
        
        curr = self.head
        while curr.next:
            curr = curr.next
        curr.next = new_node

    def reverse_list(self):
        curr = self.head
        prev = None

        while curr:
            next_node = curr.next
            curr.next = prev
            prev = curr
            curr = next_node

        self.head = prev

    def print_list(self):
        curr = self.head

        while curr:
            print(curr.data, end=" -> ")
            curr = curr.next
        print('None')


lst = LinkedList()
arr = [1,2,3,4,5,6]
for i in arr:
    lst.append(i)

lst.print_list()
lst.reverse_list()
lst.print_list()
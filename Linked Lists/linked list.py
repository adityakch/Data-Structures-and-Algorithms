class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
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

    def delete_at_beginning(self):
        self.head = self.head.next
    
    def delete_at_end(self):
        curr = self.head
        while curr.next.next:
            curr = curr.next
        curr.next = None

    def delete_nth_node(self, n):
        dummy = LinkedList()
        dummy.next = self.head
        left = dummy
        curr = self.head

        while n > 0:
            curr = curr.next
            n -= 1
        
        while curr:
            left = left.next
            curr = curr.next
        left.next = left.next.next

        self.head = dummy.next


    def print_list(self):
        curr = self.head

        while curr:
            print(curr.data, end=" -> ")
            curr = curr.next
        print('None')

lst = LinkedList()
arr = [1,2,3,6,8,7,9]
for i in arr:
    lst.append(i)

lst.print_list()
# lst.delete_at_beginning()
# lst.print_list()
# lst.delete_at_end()
# lst.print_list()
lst.delete_nth_node(4)
lst.print_list()


        
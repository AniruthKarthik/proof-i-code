# DSA CHEAT SHEET 
---

### to find the middle node of a linked list 
have 2 pointer slow and fast. move the slow pointer by one and the fast pointer by two until the fast pointer reaches the end, eventually the slow pointer will stop at the middle node 

---
### find the intersection node of two linked lists 
have 2 pointers both starting at each linked list, move the pointer simultaneously, once a pointer reaches the end of the linked list move the pointer to the head of the other linked list, repeat this until both the pointers meet at the intersection node

---
### a linked list has its end node pointing to a node X of the same linked list forming a partial circular linked list, find the node X
have 2 pointers slow and fast. move the slow pointer by 1 and the fast pointer by 2 until they both meet. once the meet each other move either of the pointer to the head of the linked list and continue moving both the pointer with step 1 until the meet, the meeting node is the node X 

note: the node X is the midpoint between the node head and the node of first intersection



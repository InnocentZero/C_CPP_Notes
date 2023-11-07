# data_structures

## Linked Lists
Yeah the good old. Can be singly linked lists, doubly, circular etc. Mostly the idea is to keep a decent brain while writing this stuff out.

## Stack

Last in first out. Can be made using an array by having a back pointer, that keeps moving back and forth as and when elements come up. Same with linked lists, have a pointer to the last node in the list and insert and remove accordingly.

## Queue

First in first out. Circular buffer. `first` points to an element that is empty and right behind the first filled element. `last` points to the position where the element is going to be filled next. One extra node is always kept empty.

- Empty: `last = (first + 1) % size`
- Full: `last = first`

## Deque

Basically a stack and queue together.

## Trees

A linked list with two pointers instead of one. Basically having a right child and a left child. Mostly class implementations will also be having a parent pointer.

- Full tree: Every node has 0 or 2 children.
- Complete tree: Filled in level order fashion.
- Perfect tree: 2<sup>n</sup> - 1 

### Binary Search Tree

All nodes on the right side of the current node are smaller in value than the current node. All on the right are greater than the current node.

- Balancing (AVL): Need to do a left rotate or a right rotate. Or a double rotate.


### Binary Heap

The top element is the minimum or maximum. All the elements below one node are larger than it (or smaller than it).

## Hash tables

Basically an array. Takes a hash function (like modulo p) and insert it in the position of h(x). If there are collisions (two inputs having the same hash), there are two approaches to resolve this.

- Linked list: It is called something I can't remember. Basically start inserting everything that collides into a linked list.

- Probing: Not what you think it is. It has categories.
    - Linear probing: if h(x) is filled, go to h(x) + 1 mod p. Keep going till you find a spot that is empty or deleted.
    - Quadratic probing: Go to h(x) + k<sup>2</sup> : if p is a prime, then you are guaranteed to find an empty bucket in p/2 probes.

If searching in the probing method, you get a cell that is deleted, then keep proceeding for the search. If you get a cell that is empty, however, the search should stop there because if the searched element was in the table, it would have occupied that one. Use an enum to keep track of full, empty and deleted.

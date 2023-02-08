Part 1: Download the starter code and implement a Linked List (List class) that works with arbitrary class objects (using a class template). You are NOT allowed to use anything from the STL, only the Node class that is included in your starter code.

The Node class is already implemented, you don't need to modify node.h. You will need to implement all member functions of the List class except print() which is already provided; you will modify list.h to do this. The following functions are members of List:

List() and ~List(): Constructor and Destructor, need to initialize members (constructor) and deallocate all nodes in list (destructor).

void print(string name): Print name, size, and values. Already implemented

int size(): Returns the size of the list.

bool empty(): Returns true if list is empty.

void insertStart(T value): Create new node with value, insert this node at the start of the list.

void insertEnd(T value): Create new node with value, insert this node at the end of the list.

void insertAt(T value, int j): Create new node with value, insert this node at position j. Position 0 is the start of the list (first node), position 1 is the second node, positon 2 is the third node, and so on...

void removeStart(): Remove node at the start of the list.

void removeEnd(): Remove node at the end of the list.

void removeAt(int j): Remove node at position j in the list.

T getFirst(): Return value of the node at the start of the list.

T getLast(): Return value of the node at the end of the list.

T getAt(int j): Return value of the node at position j.

int find(T value): Return the position of the first occurance of value in the list.

 

Part 2: Implement the ListStack and ListQueue classes using the List class.

Stack: Implement the functions in the ListStack class (modify ListStack.h):

ListStack() and ~ListStack(): Constructor and Destructor, nothing extra needs to be done here for ListStack.

void print(string name): Print name, size, and values. Already implemented

int size(): Returns the size of the stack.

bool empty(): Returns true if the stack is empty.

void push(T value): Insert value onto the "top" of the stack.

T pop(): Remove AND return value on the "top" of the stack.

Queue: Implement the functions in the ListQueue class (modify ListQueue.h):

ListQueue() and ~ListQueue(): Constructor and Destructor, nothing extra needs to be done here for ListQueue.

void print(string name): Print name, size, and values. Already implemented

int size(): Returns the size of the queue.

bool empty(): Returns true if the queue is empty.

void enqueue(T value): Insert value into the "back" of the queue.

T dequeue(): Remove AND return value from the "front" of the queue.

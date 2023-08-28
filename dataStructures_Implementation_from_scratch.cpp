// Stack:

#include <iostream>
#include <vector>

class Stack {
private:
    std::vector<int> data;

public:
    void push(int val) {
        data.push_back(val);
    }

    void pop() {
        if (!empty()) {
            data.pop_back();
        }
    }

    int top() {
        if (!empty()) {
            return data.back();
        }
        return -1; // Handle underflow.
    }

    bool empty() {
        return data.empty();
    }

    int size() {
        return data.size();
    }
};




// Queue:

#include <iostream>
#include <vector>

class Queue {
private:
    std::vector<int> data;

public:
    // enqueue method performs push_back operation on the vector.
    void enqueue(int val) {
        data.push_back(val);
    }
    // dequeue method performs erase operation on the vector.
    void dequeue() {
        if (!empty()) {
            data.erase(data.begin());
        }
    }

    int front() {
        if (!empty()) {
            return data.front();
        }
        return -1; // Handle underflow.
    }

    bool empty() {
        return data.empty();
    }

    int size() {
        return data.size();
    }
};



// Linked List:

#include <iostream>

class ListNode {
public:
    int data;
    ListNode* next;

    ListNode(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    ListNode* head;

public:
    LinkedList() : head(nullptr) {}
 
    // append method appends a new node at the end of the list.
    void append(int val) {
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
        } else {
            ListNode* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Other methods like prepend, delete, search, etc., can be added here.
};



// Doubly Linked List:

#include <iostream>

class ListNode {
public:
    int data;
    ListNode* prev;
    ListNode* next;

    ListNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    ListNode* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    // append method appends a new node at the end of the list.
    void append(int val) {
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
        } else {
            ListNode* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
    }

    // Other methods like prepend, delete, search, etc., can be added here.
};


// Binary Tree:

#include <iostream>

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;

public:

    BinaryTree() : root(nullptr) {}

    // Other methods like insert, delete, search, etc., can be added here.
};



// Binary Search Tree:


#include <iostream>

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

public:
    BinarySearchTree() : root(nullptr) {}

    // Other methods like insert, delete, search, etc., can be added here.
};


// Heap:

#include <iostream>

class Heap {
private:
    int* data;
    int capacity;
    int size;

public:

    Heap(int cap) : capacity(cap), size(0) {
        data = new int[capacity];
    }

    // Other methods like insert, delete, search, etc., can be added here.
};


// Map:

#include <iostream>

class Map {

private:
    int* keys;
    int* values;
    int capacity;
    int size;

public:

    Map(int cap) : capacity(cap), size(0) {
        keys = new int[capacity];
        values = new int[capacity];
    }

    // Other methods like insert, delete, search, etc., can be added here.
};


// Set:

#include <iostream>

class Set {

private:
    int* data;
    int capacity;
    int size;

public:

    Set(int cap) : capacity(cap), size(0) {
        data = new int[capacity];
    }

    // Other methods like insert, delete, search, etc., can be added here.
};



// Unordered Map:

#include <iostream>

class UnorderedMap {

private:
    int* keys;
    int* values;
    int capacity;
    int size;

public:

    UnorderedMap(int cap) : capacity(cap), size(0) {
        keys = new int[capacity];
        values = new int[capacity];
    }

    // Other methods like insert, delete, search, etc., can be added here.
};


// Graph:

#include <iostream>

class Graph {

private:
    int** adjMatrix;
    int numVertices;

public:

    Graph(int n) : numVertices(n) {
        adjMatrix = new int*[numVertices];
        for (int i = 0; i < numVertices; i++) {
            adjMatrix[i] = new int[numVertices];
            for (int j = 0; j < numVertices; j++) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    // Other methods like addEdge, removeEdge, etc., can be added here.
};
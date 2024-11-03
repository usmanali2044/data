#include <iostream>
using namespace std;

// Node class to represent each element in the doubly linked list
class Node {
public:
    int data;       // Data part of the node
    Node* next;     // Pointer to the next node
    Node* prev;     // Pointer to the previous node

    // Constructor to initialize a node
    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

// Doubly Linked List class to handle list operations
class DoublyLinkedList {
private:
    Node* head;     // Pointer to the first node of the linked list

public:
    // Constructor to initialize the doubly linked list
    DoublyLinkedList() {
        head = nullptr;
    }

    // Function to insert a new node at the beginning
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);  // Create a new node
        if (head == nullptr) {
            head = newNode;  // If the list is empty, set head to the new node
        } else {
            newNode->next = head;    // Link new node to current head
            head->prev = newNode;    // Link current head's previous to new node
            head = newNode;          // Update head to point to the new node
        }
    }

    // Function to insert a new node at the end
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);  // Create a new node
        if (head == nullptr) {
            head = newNode;  // If the list is empty, set head to the new node
        } else {
            Node* temp = head;
            // Traverse to the last node
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;     // Link the last node to the new node
            newNode->prev = temp;     // Link new node's previous to the last node
        }
    }

    // Function to insert a new node at a specific position
    void insertAtPosition(int data, int position) {
        if (position < 1) {
            cout << "Position should be >= 1." << endl;
            return;
        }

        Node* newNode = new Node(data);  // Create a new node
        if (position == 1) {
            insertAtBeginning(data);  // Insert at the beginning if position is 1
            return;
        }

        Node* temp = head;
        // Traverse to the node just before the specified position
        for (int i = 1; temp != nullptr && i < position - 1; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Position out of bounds." << endl;
            return;
        }

        newNode->next = temp->next;  // Link new node to the next node
        newNode->prev = temp;        // Link new node's previous to the current node

        if (temp->next != nullptr) {
            temp->next->prev = newNode;  // Update next node's previous pointer
        }

        temp->next = newNode;  // Link the current node to the new node
    }

    // Function to display the doubly linked list from head to tail
    void displayForward() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " <-> ";  // Display data
            temp = temp->next;
        }
        cout << "null" << endl;  // Indicate the end of the list
    }

    // Function to display the doubly linked list from tail to head
    void displayBackward() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        // Traverse to the last node
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        // Now traverse backward from the last node
        while (temp != nullptr) {
            cout << temp->data << " <-> ";  // Display data
            temp = temp->prev;
        }
        cout << "null" << endl;  // Indicate the start of the list
    }
};

int main() {
    DoublyLinkedList list;

    list.insertAtBeginning(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtBeginning(5);
    list.insertAtPosition(15, 3);

    cout << "Displaying list forward:" << endl;
    list.displayForward();  // Display list from head to tail

    cout << "Displaying list backward:" << endl;
    list.displayBackward();  // Display list from tail to head

    return 0;
}

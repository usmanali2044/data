#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to insert a node at the end of the list
void insertEnd(Node*& head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    
    if (head == nullptr) {  // If list is empty
        head = newNode;
        newNode->next = head;  // Point to itself, circular reference
    } else {
        Node* temp = head;
        while (temp->next != head) {  // Traverse to the last node
            temp = temp->next;
        }
        temp->next = newNode;  
        newNode->next = head;  
    }
}

// Function to insert a node at the beginning of the list
void insertBegin(Node*& head, int data) {
    Node* newNode = new Node();
    newNode->data = data;

    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {  
            temp = temp->next;
        }
        temp->next = newNode; 
        newNode->next = head;  
        head = newNode;       
    }
}


void deleteNode(Node*& head, int value) {
    if (head == nullptr) return;  // 

    
    if (head->data == value) {
        if (head->next == head) {  
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next != head) {  
            temp = temp->next;
        }
        Node* toDelete = head;
        temp->next = head->next;
        head = head->next;  // Move the head
        delete toDelete;
        return;
    }

 
    Node* curr = head;
    Node* prev = nullptr;
    do {
        prev = curr;
        curr = curr->next;
        if (curr->data == value) {
            prev->next = curr->next;
            delete curr;
            return;
        }
    } while (curr != head);
    
    cout << "Node with value " << value << " not found." << endl;
}


void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    Node* head = nullptr;

    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertBegin(head, 5);

    cout << "Circular Linked List: ";
    display(head);

    deleteNode(head, 20);
    cout << "After deletion of 20: ";
    display(head);

    return 0;
}
